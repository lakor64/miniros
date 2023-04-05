/*
 *  COPYRIGHT:        See COPYING in the top level directory
 *  PROJECT:          Linux core compatibility layer
 *  PURPOSE:          mutex functions
 *  FILE:             lxcore/lock.c
 */
#include "pch.h"
#include "lock.h"

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
