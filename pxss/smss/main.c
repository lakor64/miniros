#include "pch.h"

NTSTATUS
__cdecl
_main(IN INT argc,
      IN PCHAR argv[],
      IN PCHAR envp[],
      IN ULONG DebugFlag)
{
    NTSTATUS Status;
    KPRIORITY SetBasePriority;

    DPRINT1("smss init start\n");

    /* Make us critical */
    RtlSetProcessIsCritical(TRUE, NULL, FALSE);
    RtlSetThreadIsCritical(TRUE, NULL, FALSE);

    /* Raise our priority */
    SetBasePriority = 11;
    Status = NtSetInformationProcess(NtCurrentProcess(),
                                     ProcessBasePriority,
                                     (PVOID)&SetBasePriority,
                                     sizeof(SetBasePriority));
    ASSERT(NT_SUCCESS(Status));


    while (1);

    return STATUS_SUCCESS; /* should NEVER happend */
}
