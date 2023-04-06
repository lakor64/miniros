/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux subsystem
 * FILE:            lxss/main.c
 * PURPOSE:         Linux/POSIX subsystem driver entrypoint
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#include "pch.h"
#include "lnx32k.h"
#include <psx/lxcore.h>

_Function_class_(DRIVER_UNLOAD)
VOID
NTAPI
DriverUnload(IN PDRIVER_OBJECT DriverObject)
{
    UNREFERENCED_PARAMETER(DriverObject);

#if __LNX32K__
    CleanupUserImpl();
#endif

    return;
}

CODE_SEG("INIT")
NTSTATUS
NTAPI
DriverEntry(IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
)
{
    LXP_SUBSYSTEM_INFORMATION subsystemInformation = {0};
    NTSTATUS status;
    
    DriverObject->DriverUnload = DriverUnload;

    status = LxInitialize(DriverObject, &subsystemInformation);

    if (NT_ERROR(status))
        return status;

#if __LNX32K__
    Lnx32kRegisterCallout();
#endif

    return STATUS_SUCCESS;
}
