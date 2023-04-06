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

#ifdef _X86_
SC_ (RESTART_SYSCALL, 0)
SC_ (EXIT, 1)
SC_ (FORK, 0)
#endif
SC_ (READ, 3)
SC_ (WRITE, 3)
SC_ (OPEN, 3)
SC_ (CLOSE, 1)
