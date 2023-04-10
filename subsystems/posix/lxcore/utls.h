/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/lxcore.h
 * PURPOSE:         Internal lxcore functions
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#pragma once

NTSTATUS
NTAPI
LxpUnixPathToNTPath(IN PCSTR szUnixPath, OUT PUNICODE_STRING ntPath);

errno_t
NTAPI
LxpNtErrorToErrno(IN NTSTATUS error);

#define LxpGetCurrentPsxThreadContext() LxpProcessGetThreadContext(PsGetCurrentThread(), thd)
#define LxpGetCurrentPsxProcessContext() LxpProcessGetProcessContext(PsGetCurrentProcess(), prc)
