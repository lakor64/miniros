/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/main.c
 * PURPOSE:         win32-like driver entrypoint
 */
#include "pch.h"
#include "syscall.h"
#include "tags.h"
#include "lock.h"

extern ERESOURCE UserLock;

/* We use WIN32 threads because we don't have pico threads */
NTSTATUS NTAPI
AllocPSXThread(IN PETHREAD Thread,
               OUT PPSXTHREADINFO* W32Thread)
{
    PPSXTHREADINFO ptiCurrent;

    DPRINT1("In AllocPSXThread(0x%p)\n", Thread);

    /* Check that we were not called with an already existing Win32 thread info */
    ptiCurrent = PsGetThreadWin32Thread(Thread);
    NT_ASSERT(ptiCurrent == NULL);

    /* Allocate a new Win32 thread info */
    ptiCurrent = ExAllocatePoolWithTag(NonPagedPool,
                                       sizeof(*ptiCurrent),
                                       USERTAG_THREADINFO);
    if (ptiCurrent == NULL)
    {
        DPRINT1("Failed to allocate pti for TID:0x%lx\n",
               HandleToUlong(Thread->Cid.UniqueThread));
        return STATUS_NO_MEMORY;
    }

    DPRINT1("Allocated pti 0x%p for TID:0x%lx\n",
             ptiCurrent, HandleToUlong(Thread->Cid.UniqueThread));

    RtlZeroMemory(ptiCurrent, sizeof(*ptiCurrent));

    PsSetThreadWin32Thread(Thread, ptiCurrent, NULL);
    ObReferenceObject(Thread);
    IntReferenceThreadInfo(ptiCurrent);

    *W32Thread = ptiCurrent;
    return STATUS_SUCCESS;
}



NTSTATUS
AllocPSXProcess(IN  PEPROCESS Process,
                OUT PPSXPROCESSINFO* W32Process)
{
    PPSXPROCESSINFO ppiCurrent;

    DPRINT1("In AllocPSXProcess(0x%p)\n", Process);

    /* Check that we were not called with an already existing Win32 process info */
    ppiCurrent = PsGetProcessWin32Process(Process);
    if (ppiCurrent) return STATUS_SUCCESS;

    /* Allocate a new Win32 process info */
    ppiCurrent = ExAllocatePoolWithTag(NonPagedPool,
                                       sizeof(*ppiCurrent),
                                       USERTAG_PROCESSINFO);
    if (ppiCurrent == NULL)
    {
        DPRINT1("Failed to allocate ppi for PID:0x%lx\n",
               HandleToUlong(Process->UniqueProcessId));
        return STATUS_NO_MEMORY;
    }

    DPRINT1("Allocated ppi 0x%p for PID:0x%lx\n",
             ppiCurrent, HandleToUlong(Process->UniqueProcessId));

    RtlZeroMemory(ppiCurrent, sizeof(*ppiCurrent));

    PsSetProcessWin32Process(Process, ppiCurrent, NULL);
    IntReferenceProcessInfo(ppiCurrent);

    *W32Process = ppiCurrent;
    return STATUS_SUCCESS;
}

NTSTATUS
NTAPI
ExitThreadCallback(PETHREAD Thread)
{
	PPSXTHREADINFO ptiCurrent;

    /* Get the PSX Thread */
    ptiCurrent = PsGetThreadWin32Thread(Thread);
    ASSERT(ptiCurrent);

    DPRINT1("Destroying pti 0x%p eThread 0x%p\n", ptiCurrent, Thread);
	
    /* The thread is dying */
    PsSetThreadWin32Thread(Thread /*ptiCurrent->pEThread*/, NULL, ptiCurrent);

    /* Dereference the THREADINFO */
    IntDereferenceThreadInfo(ptiCurrent);
	
	return STATUS_SUCCESS;
}

NTSTATUS NTAPI
InitThreadCallback(PETHREAD Thread)
{
	NTSTATUS Status = STATUS_SUCCESS;
	PPSXTHREADINFO ptiCurrent;
    PEPROCESS Process;

    Process = Thread->ThreadsProcess;
	
    /* Allocate a new posix thread info */
    Status = AllocPSXThread(Thread, &ptiCurrent);
    if (!NT_SUCCESS(Status))
    {
        DPRINT1("Failed to allocate pti for TID:0x%lx\n",
               HandleToUlong(Thread->Cid.UniqueThread));
        return Status;
    }

    /* Initialize the posix thread */
    ptiCurrent->peThread = Thread;
    ptiCurrent->ppi = PsGetProcessWin32Process(Process);
	
	return STATUS_SUCCESS;
}

NTSTATUS
ExitProcessCallback(PEPROCESS Process)
{
    PPSXPROCESSINFO ppiCurrent;

    /* Get the Win32 Process */
    ppiCurrent = PsGetProcessWin32Process(Process);
    ASSERT(ppiCurrent);
    ASSERT(ppiCurrent->peProcess == Process);

    DPRINT1("Destroying ppi 0x%p\n", ppiCurrent);
	
    /* The process is dying */
    PsSetProcessWin32Process(Process, NULL, ppiCurrent);
    ppiCurrent->peProcess = NULL;

    /* Finally, dereference */
    IntDereferenceProcessInfo(ppiCurrent);

	return STATUS_SUCCESS;
}

NTSTATUS
InitProcessCallback(PEPROCESS Process)
{
    NTSTATUS Status;
    PPSXPROCESSINFO ppiCurrent;

    /* We might be called with an already allocated win32 process */
    ppiCurrent = PsGetProcessWin32Process(Process);
    if (ppiCurrent != NULL)
    {
        /* There is no more to do for us (this is a success code!) */
        return STATUS_ALREADY_WIN32; // NOTE: find a better error...
    }

    /* Allocate a new Win32 process info */
    Status = AllocPSXProcess(Process, &ppiCurrent);
    if (!NT_SUCCESS(Status))
    {
        DPRINT1("Failed to allocate ppi for PID:0x%lx\n",
               HandleToUlong(Process->UniqueProcessId));
        return Status;
    }

    /* Setup posix process */
	ppiCurrent->peProcess = Process;

	return Status;
}


/*
 * Called from IntDereferenceThreadInfo
 */
VOID
UserDeletePSXThread(PPSXTHREADINFO pti)
{
    PPSXPROCESSINFO ppi = pti->ppi;

    ObDereferenceObject(pti->peThread);

    ExFreePoolWithTag(pti, USERTAG_THREADINFO);

    IntDereferenceProcessInfo(ppi);
}

/*
 * Called from IntDereferenceProcessInfo
 */
VOID
UserDeletePSXProcess(
    _Pre_notnull_ __drv_freesMem(Mem) PPSXPROCESSINFO ppiCurrent)
{
    /* Free the PROCESSINFO */
    ExFreePoolWithTag(ppiCurrent, USERTAG_PROCESSINFO);
}


NTSTATUS
NTAPI
LxpProcessCallback(PEPROCESS Process,
                      BOOLEAN Initialize)
{
    NTSTATUS Status;

    ASSERT(Process->Peb);

    DPRINT1("LxpProcessCallback -->\n");

    UserEnterExclusive();

    if (Initialize)
    {
        Status = InitProcessCallback(Process);
    }
    else
    {
        Status = ExitProcessCallback(Process);
    }

    UserLeave();

    DPRINT1("<-- LxpProcessCallback\n");

    return Status;
}

NTSTATUS
NTAPI
LxpThreadCallback(PETHREAD Thread,
                    PSW32THREADCALLOUTTYPE Type)
{
	NTSTATUS Status;
	
	ASSERT(NtCurrentTeb());
	
	UserEnterExclusive();
	
	if (Type == PsW32ThreadCalloutInitialize)
	{
        ASSERT(PsGetThreadWin32Thread(Thread) == NULL); // PspGetPicoThreadContext
        Status = InitThreadCallback(Thread);
	}
	else
	{
		ASSERT(PsGetThreadWin32Thread(Thread) != NULL); // PspGetPicoThreadContext
		Status = ExitThreadCallback(Thread);
	}
	
	UserLeave();
	
	return Status;
}

_Function_class_(DRIVER_UNLOAD)
VOID NTAPI
DriverUnload(IN PDRIVER_OBJECT DriverObject)
{
	CleanupUserImpl();
}

CODE_SEG("INIT")
NTSTATUS
NTAPI
DriverEntry(
    IN PDRIVER_OBJECT  DriverObject,
    IN PUNICODE_STRING RegistryPath)
{
	/* Maybe move to lx32k.sys or lxss.sys? */
	WIN32_CALLOUTS_FPNS CalloutData = {0};
	
	DriverObject->DriverUnload = DriverUnload;
	
    CalloutData.ProcessCallout = LxpProcessCallback;
    CalloutData.ThreadCallout = LxpThreadCallback;
	
	/* Register our per-process and per-thread structures. */
	/* NOTE: This should be PspRegisterPicoProvider */
    PsEstablishWin32Callouts(&CalloutData);
	
    /* Init the global user lock */
    ExInitializeResourceLite(&UserLock);

	return STATUS_SUCCESS;
}
