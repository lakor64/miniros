/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/syscall.c
 * PURPOSE:         Syscall routine implementation
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "pch.h"
#include "syscall.h"


typedef long(POSIXAPI *kSyscall)(long, long, long, long, long, long);

#define DEF_SYSCALL(x) (kSyscall)(LxpSyscall_##x)

#define SYSCALL_MAX (sizeof(kSyscallTable)/sizeof(kSyscallTable[0]))

/* syscall array definition 
    https://syscalls32.paolostivanin.com/
*/
static kSyscall kSyscallTable[] = {
    NULL, // restart_syscall
    NULL, //exit
    NULL, // fork
    NULL, // read
    DEF_SYSCALL(WRITE),
    DEF_SYSCALL(OPEN),
    DEF_SYSCALL(CLOSE),
};

/*
    Keep this exported until we figure out a way to include psxsc.dll in a sane way...
*/
long
NTAPI
LxpSysDispatch(long id, long p1, long p2, long p3, long p4, long p5, long p6)
{
    /* TODO: Figure out a better way to do this, as we don't have psxsc.dll yet... */
    if (id >= SYSCALL_MAX)
    {
        DPRINT1("Syscall %d not supported", id);
        return -1;
    }

    if (kSyscallTable[id] == NULL)
    {
        DPRINT1("Syscall %d not supported", id);
        return -1;
    }

    return kSyscallTable[id](p1, p2, p3, p4, p5, p6);
}
