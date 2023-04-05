/*
 *  COPYRIGHT:        See COPYING in the top level directory
 *  PROJECT:          Linux core compatibility layer
 *  PURPOSE:          mutex functions
 *  FILE:             lxcore/lock.h
 */

#pragma once

VOID FASTCALL CleanupUserImpl(VOID);
VOID FASTCALL UserEnterExclusive(VOID);
VOID FASTCALL UserLeave(VOID);
BOOLEAN FASTCALL UserIsEntered(VOID);
BOOLEAN FASTCALL UserIsEnteredExclusive(VOID);
