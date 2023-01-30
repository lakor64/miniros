/*
* @file syscall_arch.h
* @brief psxsyscall import routines for POSIX NT subsystem
*/
#ifndef NT_PSXIMPORT_H
#define NT_PSXIMPORT_H

extern __declspec(dllimport) long __syscall1(long n, long long a1);
extern __declspec(dllimport) long __syscall2(long n, long long a1, long long a2);
extern __declspec(dllimport) long __syscall3(long n, long long a1, long long a2, long long a3);
extern __declspec(dllimport) long __syscall4(long n, long long a1, long long a2, long long a3, long long a4);
extern __declspec(dllimport) long __syscall5(long n, long long a1, long long a2, long long a3, long long a4, long long a5);
extern __declspec(dllimport) long __syscall6(long n, long long a1, long long a2, long long a3, long long a4, long long a5, long long a6);

#endif
