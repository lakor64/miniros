/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/main.c
 * PURPOSE:         Driver entrypoint
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "pch.h"

NTSTATUS
NTAPI
LxInitialize(IN PDRIVER_OBJECT DriverObject,
    IN PLXP_SUBSYSTEM_INFORMATION SubsystemInformation
)
{
    NTSTATUS Status;

#if NTDDI_VERSION >= NTDDI_WINTHRESHOLD
    Status = LxpPicoInitialize();
    if (NT_ERROR(Status))
        return Status;
#endif

    Status = LxpSsInitialize();

    /* do we need to init anything else? */

    return Status;
}


CODE_SEG("INIT")
NTSTATUS
NTAPI
DriverEntry(IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
)
{
    /* not used */

    UNREFERENCED_PARAMETER(DriverObject);
    UNREFERENCED_PARAMETER(RegistryPath);
    
    return STATUS_SUCCESS;
}
