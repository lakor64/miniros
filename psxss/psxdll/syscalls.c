/*
	POSIX syscall translations for NT (psxdll.dll)
*/
#include "psxdll.h"

LONG sys_write(LONG_PTR fd, LPCVOID buf, ULONG count)
{
	NTSTATUS status;
	IO_STATUS_BLOCK iob;

	status = ZwWriteFile((HANDLE)fd, NULL, NULL, NULL, &iob, (PVOID)buf, count, NULL, NULL);

	if (!NT_SUCCESS(status) || !NT_SUCCESS(iob.Status))
		return -1;

	return (LONG)iob.Information;
}

LONG_PTR sys_open(LPCSTR name, INT flags /*, umode_t mode */)
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
		return -1;

	return (LONG_PTR)handle;
}

LONG sys_close(LONG_PTR fd)
{
	NTSTATUS status = ZwClose((HANDLE)fd);
	if (!NT_SUCCESS(status))
	{
		return -1;
	}

	return 0;
}
