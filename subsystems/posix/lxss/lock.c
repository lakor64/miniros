/*
 *  COPYRIGHT:        See COPYING in the top level directory
 *  PROJECT:          Linux subsystem
 *  PURPOSE:          mutex functions
 *  FILE:             lxss/lock.c
 */
#include "pch.h"
#include "lnx32k.h"

ERESOURCE UserLock;

/*
RETURN
   True if current thread owns the lock (possibly shared)
*/
BOOLEAN FASTCALL UserIsEntered(VOID)
{
    return ExIsResourceAcquiredExclusiveLite(&UserLock) ||
           ExIsResourceAcquiredSharedLite(&UserLock);
}

BOOLEAN FASTCALL UserIsEnteredExclusive(VOID)
{
    return ExIsResourceAcquiredExclusiveLite(&UserLock);
}

VOID FASTCALL CleanupUserImpl(VOID)
{
    ExDeleteResourceLite(&UserLock);
}

// Win: EnterCrit
VOID FASTCALL UserEnterExclusive(VOID)
{
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&UserLock, TRUE);
}

// Win: LeaveCrit
VOID FASTCALL UserLeave(VOID)
{
    ASSERT(UserIsEntered());
    ExReleaseResourceLite(&UserLock);
    KeLeaveCriticalRegion();
}
