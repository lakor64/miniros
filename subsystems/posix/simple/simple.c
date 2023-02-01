/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Posix syscall compatibility layer
 * FILE:            psxss/simple/simple.c
 * PURPOSE:         Simple POSIX test application
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include <nt/syscalls.h>
#include <nt/debug.h>

void _start()
{
    DPRINT1("simple app start\n");

    const char msg[] = "Hello from POSIX userland!";
	NTSYS_write((handle_t)1, msg, sizeof(msg)-1);

    while(1); // die...
}
