/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Posix syscall compatibility layer
 * FILE:            posix/psxsc/file.c
 * PURPOSE:         POSIX file syscalls implementations for NT
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "stdafx.h"

POSIXAPI ssize_t NTSYS_write(handle_t fd, const void* buf, size_t count)
{
	NTSTATUS status;
	IO_STATUS_BLOCK iob;

	status = ZwWriteFile((HANDLE)fd, NULL, NULL, NULL, &iob, (PVOID)buf, count, NULL, NULL);

	if (!NT_SUCCESS(status) || !NT_SUCCESS(iob.Status))
		return -1;

	return (long)iob.Information;
}

POSIXAPI handle_t NTSYS_open(const char* name, int flags /*, umode_t mode */)
{
	HANDLE handle;
	IO_STATUS_BLOCK iob;
	OBJECT_ATTRIBUTES obj;
	UNICODE_STRING str;
	ANSI_STRING astr;
	NTSTATUS status;

	RtlInitAnsiString(&astr, name);
	RtlAnsiStringToUnicodeString(&str, &astr, FALSE);

	InitializeObjectAttributes(&obj, &str, 0, NULL, NULL);
	status = ZwOpenFile(&handle, GENERIC_READ, &obj, &iob, FILE_SHARE_READ, 0);

	if (!NT_SUCCESS(status))
		return (handle_t)-1;

	return (handle_t)handle;
}

POSIXAPI long NTSYS_close(handle_t fd)
{
	NTSTATUS status = ZwClose((HANDLE)fd);
	if (!NT_SUCCESS(status))
	{
		return -1;
	}

	return 0;
}
