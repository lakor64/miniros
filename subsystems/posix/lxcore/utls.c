/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/utls.c
 * PURPOSE:         Utility functions
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "pch.h"
#include "utls.h"

NTSTATUS
NTAPI
LxpUnixPathToNTPath(IN PCSTR szUnixPath, OUT PUNICODE_STRING ntPath)
{
    if (!szUnixPath || !ntPath) return STATUS_OBJECT_NAME_INVALID;

    /* UNIMPLEMENTED */

    ntPath->Buffer = NULL;
    ntPath->Length = 0;

    return STATUS_NOT_IMPLEMENTED;
}

errno_t
NTAPI
LxpNtErrorToErrno(IN NTSTATUS error)
{
    /* UNIMPLEMENTED */
    return EINVAL;
}
