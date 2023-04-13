/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Posix System library
 * FILE:            simple/simple.c
 * PURPOSE:         Simple POSIX test application
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */

#define NTOS_MODE_USER
#include <ndk/cmfuncs.h>
#include <reactos/debug.h>

#include <psx/types.h>

extern long __stdcall write(unsigned int fd, const char* buf, ssize_t count);

void __PosixProcessStartup()
{
    DPRINT1("simple.exe startup!\n");

    write(0, "Hello posix universe", 20);
    while(1); // die...
}
