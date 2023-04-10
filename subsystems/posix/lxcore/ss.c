/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/ss.c
 * PURPOSE:         NT subsystem routines (for lnx32k / psxss)
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "pch.h"
#include "syscall.h"

#define SC_(uppername, lowername, argcount) (ULONG_PTR)(LxpSyscall_##uppername),
ULONG_PTR Lnx32kSDDT[] = {
#include <psx/sclist.h>
};
#undef SC_

#define SC_(uppername, lowername, argcount) argcount * sizeof(void*),
UCHAR Lnx32kSPPT[] = {
#include <psx/sclist.h>
};
#undef SC_

#define NUMBER_OF_SYSCALLS    (sizeof(Lnx32kSPPT) / sizeof(Lnx32kSPPT[0]))
#define MAX_SYSCALL_NUMBER    0x1000 + (NUMBER_OF_SYSCALLS - 1)
ULONG Lnx32kNumberOfSysCalls = NUMBER_OF_SYSCALLS;

NTAPI NTSTATUS LxpSsInitialize(VOID)
{
    BOOLEAN Result;

    /*
        User-mode POSIX subsystem syscalls
        (service index = 2)
    */
    Result = KeAddSystemServiceTable(Lnx32kSDDT, NULL, Lnx32kNumberOfSysCalls, Lnx32kSPPT, 2);

    if (Result == FALSE)
    {
        DPRINT1("Cannot register System service table 2!!!!\n");
        return STATUS_UNSUCCESSFUL;
    }

    return STATUS_SUCCESS;
}
