/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Posix syscall compatibility layer
 * FILE:            posix/psxsc/file.c
 * PURPOSE:         DLL entrypoint wrapper
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "stdafx.h"

BOOL NTAPI DllMainCRTStartup(HINSTANCE hInstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    DPRINT1("POSIX DLLMAIN %x %d %x\n", hInstDLL, fdwReason, lpReserved);
    return TRUE;
}
