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

#include <unistd.h>

void __PosixProcessStartup()
{
    size_t m = 0;

    DPRINT1("simple.exe startup!\n");

    m = write(0, "Hello posix universe", 20);

    DPRINT1("write result is %d\n", m);

    while(1); // die...
}
