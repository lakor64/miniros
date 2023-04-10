/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux/POSIX core compatibility layer
 * FILE:            psx/sclist.h
 * PURPOSE:         LXCore syscall list
 * REFERENCE:       https://syscalls32.paolostivanin.com/
 *                  https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
 */

// ex.: LxpSyscall_WRITE

// KEEP IN SYNC WITH lxcore/syscall.h
// #define SC_(uppername, lowername, argcount)

#ifdef _M_IX86
SC_ (RESTART_SYSCALL, restart_syscall, 0)
SC_ (EXIT, exit, 1)
SC_ (FORK, fork, 0)
#endif
SC_ (READ, read, 3)
SC_ (WRITE, write, 3)
SC_ (OPEN, open, 3)
SC_ (CLOSE, close, 1)
