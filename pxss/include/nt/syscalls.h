/*
 * syscalls.h - NT posix syscall layer
 */
#pragma once

LONG sys_write(LONG_PTR fd, LPCVOID buf, ULONG count);
LONG_PTR sys_open(LPCSTR name, INT flags /*, umode_t mode */);
LONG sys_close(LONG_PTR fd);
