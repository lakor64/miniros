#include "pch.h"

NTSTATUS
__cdecl
_main(IN INT argc,
      IN PCHAR argv[],
      IN PCHAR envp[],
      IN ULONG DebugFlag)
{
    DPRINT1("smss init start\n");

    while (1);
    return STATUS_SUCCESS;
}
