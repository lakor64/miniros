/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS Client/Server Runtime SubSystem
 * FILE:            psxss/psxss.c
 * PURPOSE:         POSIX Subsystem Executable Code
 * REFERENCE:       csrss, csrsrv
 */

/* INCLUDES *******************************************************************/

#define NTOS_MODE_USER
#include <ndk/exfuncs.h>
#include <ndk/psfuncs.h>
#include <ndk/rtlfuncs.h>
#include <ndk/lpcfuncs.h>
#include <ndk/obfuncs.h>

#define NDEBUG
#include <debug.h>

#include <sm/smmsg.h>

UNICODE_STRING PsxSbApiPortName = RTL_CONSTANT_STRING(L"\\POSIX\\SbApiPort");
UNICODE_STRING PsxDirectoryName = RTL_CONSTANT_STRING(L"\\POSIX");
HANDLE PsxObjectDirectory = NULL;
HANDLE PsxSbApiPort = NULL;
HANDLE CsrHeap = NULL;
//PCSR_THREAD CsrSbApiRequestThreadPtr;

VOID
NTAPI
CsrSbApiRequestThread(IN PVOID Parameter);

/* FUNCTIONS ******************************************************************/

/*++
 * @name CsrCreateLocalSystemSD
 *
 * The CsrCreateLocalSystemSD routine creates a Security Descriptor for
 * the local account with PORT_ALL_ACCESS.
 *
 * @param LocalSystemSd
 *        Pointer to a pointer to the security descriptor to create.
 *
 * @return STATUS_SUCCESS in case of success, STATUS_UNSUCCESSFUL otherwise.
 *
 * @remarks None.
 *
 *--*/
NTSTATUS
NTAPI
CsrCreateLocalSystemSD(OUT PSECURITY_DESCRIPTOR *LocalSystemSd)
{
    SID_IDENTIFIER_AUTHORITY NtSidAuthority = {SECURITY_NT_AUTHORITY};
    PSID SystemSid;
    ULONG Length;
    PSECURITY_DESCRIPTOR SystemSd;
    PACL Dacl;
    NTSTATUS Status;

    /* Initialize the System SID */
    RtlAllocateAndInitializeSid(&NtSidAuthority, 1,
                                SECURITY_LOCAL_SYSTEM_RID,
                                0, 0, 0, 0, 0, 0, 0,
                                &SystemSid);

    /* Get the length of the SID */
    Length = RtlLengthSid(SystemSid) + sizeof(ACL) + sizeof(ACCESS_ALLOWED_ACE);

    /* Allocate a buffer for the Security Descriptor, with SID and DACL */
    SystemSd = RtlAllocateHeap(CsrHeap, 0, SECURITY_DESCRIPTOR_MIN_LENGTH + Length);

    /* Set the pointer to the DACL */
    Dacl = (PACL)((ULONG_PTR)SystemSd + SECURITY_DESCRIPTOR_MIN_LENGTH);

    /* Now create the SD itself */
    Status = RtlCreateSecurityDescriptor(SystemSd, SECURITY_DESCRIPTOR_REVISION);
    if (!NT_SUCCESS(Status)) goto Quit;

    /* Create the DACL for it */
    RtlCreateAcl(Dacl, Length, ACL_REVISION2);

    /* Create the ACE */
    Status = RtlAddAccessAllowedAce(Dacl, ACL_REVISION, PORT_ALL_ACCESS, SystemSid);
    if (!NT_SUCCESS(Status)) goto Quit;

    /* Clear the DACL in the SD */
    Status = RtlSetDaclSecurityDescriptor(SystemSd, TRUE, Dacl, FALSE);
    if (!NT_SUCCESS(Status)) goto Quit;

Quit:
    if (!NT_SUCCESS(Status))
    {
        RtlFreeHeap(CsrHeap, 0, SystemSd);
        SystemSd = NULL;
    }

    /* Free the SID and return*/
    RtlFreeSid(SystemSid);
    *LocalSystemSd = SystemSd;
    return Status;
}

VOID
NTAPI
PsxpSetDefaultProcessHardErrorMode(VOID)
{
    ULONG DefaultHardErrorMode = 0;

    /* Disable hard errors */
    NtSetInformationProcess(NtCurrentProcess(),
                            ProcessDefaultHardErrorMode,
                            &DefaultHardErrorMode,
                            sizeof(DefaultHardErrorMode));
}

/*++
 * @name CsrSbApiPortInitialize
 *
 * The CsrSbApiPortInitialize routine initializes the LPC Port used for
 * communications with the Session Manager (SM) and initializes the static
 * thread that will handle connection requests and APIs.
 *
 * @param None
 *
 * @return STATUS_SUCCESS in case of success, STATUS_UNSUCCESSFUL otherwise.
 *
 * @remarks None.
 *
 *--*/
NTSTATUS
NTAPI
CsrSbApiPortInitialize(VOID)
{
    PSECURITY_DESCRIPTOR PortSd;
    OBJECT_ATTRIBUTES ObjectAttributes;
    NTSTATUS Status;
    HANDLE hRequestThread;
    CLIENT_ID ClientId;

    /* Create Security Descriptor for this Port */
    Status = CsrCreateLocalSystemSD(&PortSd);
    if (!NT_SUCCESS(Status)) return Status;

    /* Initialize the Attributes */
    InitializeObjectAttributes(&ObjectAttributes,
                               &PsxSbApiPortName,
                               0,
                               NULL,
                               PortSd);

    /* Create the Port Object */
    Status = NtCreatePort(&PsxSbApiPort,
                          &ObjectAttributes,
                          sizeof(SB_CONNECTION_INFO),
                          sizeof(SB_API_MSG),
                          32 * sizeof(SB_API_MSG));
    if (PortSd) RtlFreeHeap(CsrHeap, 0, PortSd);

    if (NT_SUCCESS(Status))
    {
        /* Create the Thread to handle the API Requests */
        Status = RtlCreateUserThread(NtCurrentProcess(),
                                     NULL,
                                     TRUE,
                                     0,
                                     0,
                                     0,
                                     (PVOID)CsrSbApiRequestThread,
                                     NULL,
                                     &hRequestThread,
                                     &ClientId);
        if (NT_SUCCESS(Status))
        {
            /* Add it as a Static Server Thread */
            /*CsrSbApiRequestThreadPtr = CsrAddStaticServerThread(hRequestThread,
                                                                &ClientId,
                                                                0);*/

            /* Activate it */
            Status = NtResumeThread(hRequestThread, NULL);
        }
    }

    return Status;
}

int
_cdecl
_main(int argc,
      char *argv[],
      char *envp[],
      int DebugFlag)
{
    KPRIORITY BasePriority = PROCESS_PRIORITY_NORMAL_FOREGROUND + 4;
    NTSTATUS Status;
    OBJECT_ATTRIBUTES ObjectAttributes;

    UNREFERENCED_PARAMETER(envp);
    UNREFERENCED_PARAMETER(DebugFlag);

    /* Set the base priority */
    NtSetInformationProcess(NtCurrentProcess(),
                            ProcessBasePriority,
                            &BasePriority,
                            sizeof(BasePriority));

    CsrHeap = RtlGetProcessHeap();
    
    /* Create dir object */
    InitializeObjectAttributes(&ObjectAttributes,
                                &PsxDirectoryName,
                                OBJ_OPENIF | OBJ_CASE_INSENSITIVE | OBJ_PERMANENT,
                                NULL,
                                NULL);
    Status = NtCreateDirectoryObject(&PsxObjectDirectory,
                                        DIRECTORY_ALL_ACCESS,
                                        &ObjectAttributes);

    if (!NT_SUCCESS(Status))
    {
        DPRINT1("PSXSS dir object fail %x\n", Status);
        return -1;
    }

    /* Connect to smss */
    Status = CsrSbApiPortInitialize();

    if (!NT_SUCCESS(Status))
    {
        DPRINT1("PSXSS SmApi connect fail %x\n", Status);
        return -1;
    }
    
    /* Disable errors */
    PsxpSetDefaultProcessHardErrorMode();

    /* If this is Session 0, make sure killing us bugchecks the system */
    if (NtCurrentPeb()->SessionId == 0) RtlSetProcessIsCritical(TRUE, NULL, FALSE);

    /* Kill this thread. CSRSRV keeps us going */
    NtTerminateThread(NtCurrentThread(), Status);
    return 0;
}

/* EOF */
