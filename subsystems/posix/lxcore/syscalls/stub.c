/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            posix/psxsc/dummy.c
 * PURPOSE:         Stub system calls
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "pch.h"
#include "syscall.h"

long POSIXAPI LxpSyscall_RESTART_SYSCALL(void)
{
    /* UNIMPLEMENTED */
    return -1;
}

pid_t POSIXAPI LxpSyscall_FORK(void)
{
    /* UNIMPLEMENTED */
    return -1;
}

void POSIXAPI LxpSyscall_EXIT(int error_code)
{
    DPRINT1("LxpSyscall_EXIT %d\n", error_code);
    /* UNIMPLEMENTED */
}