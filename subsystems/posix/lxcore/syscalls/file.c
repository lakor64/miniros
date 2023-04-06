/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/syscalls/file.c
 * PURPOSE:         POSIX file syscalls implementations for NT
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "pch.h"
#include "syscall.h"

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

	PAGED_CODE();

	// TODO! Broken code on x64, we should store linux fd somewhere else (eg: TEB)

	/*status = NtWriteFile((HANDLE)fd, NULL, NULL, NULL, &iob, (PVOID)buf, count, NULL, NULL);

	if (!NT_SUCCESS(status) || !NT_SUCCESS(iob.Status))
		return -1;

	return (long)iob.Information;*/
	return -1;
}

long
POSIXAPI
LxpSyscall_OPEN(const char *name, int flags, umode_t mode)
{
	/*HANDLE handle;
	IO_STATUS_BLOCK iob;
	OBJECT_ATTRIBUTES obj;
	UNICODE_STRING str;
	ANSI_STRING astr;
	NTSTATUS status;*/

	PAGED_CODE();

	// We need to validate user-land buffer "name" here!
	

	// TODO: Convert from POSIX to NT (like Win32 CreateFileW)
	// Should we default to use UTF8 ?

	/*RtlInitAnsiString(&astr, name);
	RtlAnsiStringToUnicodeString(&str, &astr, FALSE);

	InitializeObjectAttributes(&obj, &str, 0, NULL, NULL);
	status = NtOpenFile(&handle, GENERIC_READ, &obj, &iob, FILE_SHARE_READ, 0);

	if (!NT_SUCCESS(status))
		return -1;

	return (long)handle;*/
	return -1;
}

long
POSIXAPI
LxpSyscall_CLOSE(unsigned int fd)
{
	PAGED_CODE();
	
	/*
	NTSTATUS status = NtClose((HANDLE)fd);
	if (!NT_SUCCESS(status))
	{
		return -1;
	}*/

	return 0;
}

ssize_t
POSIXAPI
LxpSyscall_READ(unsigned int fd, char* buf, size_t count)
{
	PAGED_CODE();

	return 0;
}
