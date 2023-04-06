/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/main.c
 * PURPOSE:         Threshold Pico process registration
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "pch.h"
#include "pico.h"
#include "syscall.h"

#if NTDDI_VERSION >= NTDDI_WINTHRESHOLD

/* syscall definitions */

typedef long(POSIXAPI *LxSysCall)(long, long, long, long, long, long);
#define SYSCALL_MAX (sizeof(LxpSysCallTable)/sizeof(LxpSysCallTable[0]))

#define SC_(x, d) (LxSysCall)(LxpSyscall_##x);
static LxSysCall LxpSysCallTable[] = {
#include <psx/sclist.h>
};
#undef SC_

VOID NTAPI LxpDispatchSystemCall(IN PPS_PICO_SYSTEM_CALL_INFORMATION SystemCall)
{
#ifdef _AMD64_
    ULONG id = SystemCall->TrapFrame->Rax;
    if (id >= SYSCALL_MAX)
    {
        DPRINT1("Syscall %lu not supported (id > %u)", id, SYSCALL_MAX);
        SystemCall->TrapFrame->Rax = -1;
        return;
    }

    if (LxpSyscallTable[id] == NULL)
    {
        DPRINT1("Syscall %lu not supported (value is null)", id);
        SystemCall->TrapFrame->Rax = -1;
        return;
    }

    SystemCall->TrapFrame->Rax = LxpSyscallTable[id](SystemCall->TrapFrame->Rdi, SystemCall->TrapFrame->Rsi, SystemCall->TrapFrame->Rdx, SystemCall->TrapFrame->R10, SystemCall->TrapFrame->R8, SystemCall->TrapFrame->R9);
#elif _X86_
    ULONG id = SystemCall->TrapFrame->Eax;
    if (id >= SYSCALL_MAX)
    {
        DPRINT1("Syscall %lu not supported (id > %u)", id, SYSCALL_MAX);
        SystemCall->TrapFrame->Eax = -1;
        return;
    }

    if (LxpSyscallTable[id] == NULL)
    {
        DPRINT1("Syscall %lu not supported (value is null)", id);
        SystemCall->TrapFrame->Rax = -1;
        return;
    }

    SystemCall->TrapFrame->Eax = LxpSyscallTable[id](SystemCall->TrapFrame->Ebx, SystemCall->TrapFrame->Ecd, SystemCall->TrapFrame->Edx, SystemCall->TrapFrame->Esi, SystemCall->TrapFrame->Edi, SystemCall->TrapFrame->Ebp);
#else
    #error "lxcore calling convention missing"
#endif
}

static PS_PICO_PROVIDER_ROUTINES LxpPicoRoutines = {
    sizeof(PS_PICO_PROVIDER_ROUTINES),
    LxpDispatchSystemCall,
    /* TODO */
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    GENERIC_ALL,
    GENERIC_ALL,
};

NTSTATUS NTAPI LxpPicoInitialize()
{
    PS_PICO_ROUTINES rt = {0};
    rt.Size = sizeof(rt);

    NTSTATUS Status = PsRegisterPicoProvider(&LxpPicoRoutines, &rt);

    /* TODO: Initialize lxmanager lpc */

    return Status;
}
#endif
