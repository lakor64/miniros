/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/syscall.h
 * PURPOSE:         Syscall definitions
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#pragma once

/* syscall definitions */

ssize_t POSIXAPI LxpSyscall_WRITE(unsigned int fd, const char *buf, size_t count);
long POSIXAPI LxpSyscall_OPEN(const char *name, int flags, umode_t mode);
long POSIXAPI LxpSyscall_CLOSE(unsigned int fd);
