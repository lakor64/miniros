/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Posix syscall compatibility layer
 * FILE:            psxss/include/nt/syscalls.h
 * PURPOSE:         POSIX syscalls for NT
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#ifndef _POSIX_NT_SYSCALLS_H_
#define _POSIX_NT_SYSCALLS_H_

#include <nt/types.h>

POSIXAPI handle_t NTSYS_open(const char* pathname, int flags);
POSIXAPI long NTSYS_close(handle_t fd);
POSIXAPI ssize_t NTSYS_write(handle_t fd, const void* buf, size_t count);

#endif
