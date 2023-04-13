/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/syscalls/file.c
 * PURPOSE:         POSIX file syscalls implementations for NT
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "pch.h"
#include "syscall.h"
#include "utls.h"

long
POSIXAPI
LxpSyscall_OPEN(const char *name, int flags, umode_t mode)
{
	NTSTATUS status;
	OBJECT_ATTRIBUTES obj;
	PPSXFD fd = NULL;
	PPSXTHREADINFO thd = LxpGetCurrentPsxThreadContext();
	ACCESS_MASK mask = 0;
	IO_STATUS_BLOCK iob;
	ULONG shareMask = 0, cDisp = 0;
	long handle = 0;
	UNICODE_STRING NtName;


	PAGED_CODE();

	if (flags & O_RDONLY)
	{
		mask = GENERIC_READ;
		shareMask = FILE_SHARE_READ;
		cDisp = FILE_OPEN;
	}
	else if (flags & O_WRONLY)
	{
		mask = GENERIC_WRITE;
		shareMask = FILE_SHARE_WRITE;
		cDisp = FILE_OVERWRITE;
	}
	else if (flags & O_RDWR)
	{
		mask = GENERIC_READ | GENERIC_WRITE;
		shareMask = FILE_SHARE_READ | FILE_SHARE_WRITE;
		cDisp = FILE_OVERWRITE;
	}
	else
	{
		thd->ThreadError = EINVAL;
		return -1;
	}

	if (thd->ppi->OpenedFD >= MAX_PROCESS_FD)
	{
		thd->ThreadError = EMFILE;
		return -1;
	}

	fd = ExAllocatePoolWithTag(PagedPool, sizeof(PSXFD), PSXFD_TAG);

	if (!fd)
	{
		thd->ThreadError = ENOMEM;
		return -1;
	}

	status = LxpUnixPathToNTPath(name, &NtName);

	if (NT_ERROR(status))
	{
		thd->ThreadError = LxpNtErrorToErrno(status);
		ExFreePoolWithTag(fd, PSXFD_TAG);
		return -1;
	}

	DPRINT1("lxpsyscall open ntpath: %S flags: %d mode: %d\n", NtName.Buffer, flags, mode);

	InitializeObjectAttributes(&obj, &NtName, 0, NULL, NULL);
	status = ZwCreateFile(&fd->NtHandle, mask, &obj, &iob, NULL, 0, shareMask, cDisp, 0, NULL, 0);

	if (NT_ERROR(status))
	{
		thd->ThreadError = LxpNtErrorToErrno(status);
		goto err;
	}

	/* Find first available handle */
	for (; handle < MAX_PROCESS_FD; handle++)
	{
		if (thd->ppi->Files[handle] == NULL)
		{
			thd->ppi->Files[handle] = fd;
			thd->ppi->OpenedFD++;
			thd->ThreadError = 0;
			return handle;
		}
	}

	thd->ThreadError = EMFILE;
	
err:
	ExFreePool(NtName.Buffer);
	ExFreePoolWithTag(fd, PSXFD_TAG);
	return -1;
}

long
POSIXAPI
LxpSyscall_CLOSE(unsigned int fd)
{
	PPSXTHREADINFO thd = LxpGetCurrentPsxThreadContext();
	NTSTATUS status;

	PAGED_CODE();

	/* Check if this handle is valid */
	if (fd >= MAX_PROCESS_FD || thd->ppi->Files[fd] == NULL)
	{
		thd->ThreadError = EBADF;
		return -1;
	}

	status = ZwClose(thd->ppi->Files[fd]->NtHandle);

	if (NT_ERROR(status))
	{
		/* handle not closed! */
		thd->ThreadError = LxpNtErrorToErrno(status);
		return -1;
	}

	ExFreePoolWithTag(thd->ppi->Files[fd], PSXFD_TAG);
	thd->ppi->Files[fd] = NULL;
	thd->ThreadError = 0;
	return 0;
}

ssize_t
POSIXAPI
LxpSyscall_READ(unsigned int fd, char* buf, size_t count)
{
	PPSXTHREADINFO thd = LxpGetCurrentPsxThreadContext();

	PAGED_CODE();

	thd->ThreadError = ENOSYS;
	return -1;
}


/* ksys_read */
ssize_t
POSIXAPI
LxpSyscall_WRITE(unsigned int fd, const char *buf, size_t count)
{
	/*
		Previous mode (psxsc.dll -> lxcore.sys) should be set into user-mode, therefore we
			only need to fetch FDs and not bother about buffer conversion.
	*/

	/*NTSTATUS status;
	IO_STATUS_BLOCK iob;*/

	//PPSXTHREADINFO thd = LxpGetCurrentPsxThreadContext();

	DPRINT1("LxpSyscall_WRITE: FD %u BUF %s COUNT %u\n", fd, buf, count);

	//PAGED_CODE();

	// TODO! Broken code on x64, we should store linux fd somewhere else (eg: TEB)

	/*status = NtWriteFile((HANDLE)fd, NULL, NULL, NULL, &iob, (PVOID)buf, count, NULL, NULL);

	if (!NT_SUCCESS(status) || !NT_SUCCESS(iob.Status))
		return -1;

	return (long)iob.Information;*/

	//thd->ThreadError = ENOSYS;
	return -1;
}
