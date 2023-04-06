/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux subsystem
 * FILE:            lxss/lx32k.h
 * PURPOSE:         lnx32k inclusions
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#pragma once

#include <psx/process.h>

/* locking functions from win32ss/user/ntuser/ntuser.c */
VOID FASTCALL CleanupUserImpl(VOID);
VOID FASTCALL UserEnterExclusive(VOID);
VOID FASTCALL UserLeave(VOID);
BOOLEAN FASTCALL UserIsEntered(VOID);
BOOLEAN FASTCALL UserIsEnteredExclusive(VOID);

/* delete/create functions */
VOID UserDeletePSXThread(PPSXTHREADINFO);
VOID UserDeletePSXProcess(_Pre_notnull_ __drv_freesMem(Mem) PPSXPROCESSINFO);

/* subsystem entrypoint for nt kernel */
VOID Lnx32kRegisterCallout(VOID);

/* memory tags */
#define USERTAG_THREADINFO               'itsU'
#define USERTAG_PROCESSINFO              'ipsU'

/* reference count */
#define IntReferenceThreadInfo(pti) \
    InterlockedIncrement(&(pti)->RefCount)

#define IntDereferenceThreadInfo(pti) \
do { \
    if (InterlockedDecrement(&(pti)->RefCount) == 0) \
    { \
        UserDeletePSXThread(pti); \
    } \
} while(0)

#define IntReferenceProcessInfo(ppi) \
    InterlockedIncrement((volatile LONG*)(&(ppi)->RefCount))

#define IntDereferenceProcessInfo(ppi) \
do { \
    if (InterlockedDecrement((volatile LONG*)(&(ppi)->RefCount)) == 0) \
    { \
        UserDeletePSXProcess(ppi); \
    } \
} while(0)
