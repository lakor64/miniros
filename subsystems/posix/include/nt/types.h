/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Posix syscall compatibility layer
 * FILE:            psxss/include/nt/types.h
 * PURPOSE:         Simple CRT types for applications that uses psxsc
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */

#ifndef _POSIX_TYPES_H_
#define _POSIX_TYPES_H_

#ifndef _INC_CRTDEFS // ROS-CRT
typedef unsigned long size_t;
#endif

typedef signed long ssize_t;
typedef long* handle_t;

#ifndef POSIXAPI
#define POSIXAPI __cdecl
#endif

#endif
