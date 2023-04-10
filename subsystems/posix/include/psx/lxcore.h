/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux/POSIX core compatibility layer
 * FILE:            psx/lxcore.h
 * PURPOSE:         LXCore definitions
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 * REFERENCES:      https://github.com/ionescu007/lxss/blob/6a3040fadff5ce43d7bfd638a4e5d7dfe8780143/lxdrv/lxvfs.h
 */
#pragma once

//
// Opaque types
//
typedef struct _LX_INSTANCE* PLX_INSTANCE;
typedef struct _VFS_MINOR_DEVICE* PVFS_MINOR_DEVICE;

//
// Namespace Initialization Callback and Registration
//
typedef
INT
(VFS_MOUNT_NAMESPACE_INITIALIZE_CALLBACK) (
    IN PLX_INSTANCE Instance
    );
typedef VFS_MOUNT_NAMESPACE_INITIALIZE_CALLBACK *PVFS_MOUNT_NAMESPACE_INITIALIZE_CALLBACK;
typedef struct _LXP_SUBSYSTEM_INFORMATION
{
    PVFS_MOUNT_NAMESPACE_INITIALIZE_CALLBACK MountNamespaceInitialize;
} LXP_SUBSYSTEM_INFORMATION, *PLXP_SUBSYSTEM_INFORMATION;

NTSTATUS
NTAPI
LxInitialize (
    IN PDRIVER_OBJECT DriverObject,
    IN PLXP_SUBSYSTEM_INFORMATION SubsystemInformation
);

// lx internal api

// NOTE: Using PsWin32 context might kill everything is lxss.sys is not registred in lnx32k mode

#if NTDDI_VERSION >= NTDDI_WINTHRESHOLD
// TODO: Ps PicoProcess Context are not correct nor we care for fixing

#define LxpProcessGetProcessContext(proc, ret) \
    { \
        if (x->PicoCreated) \
            ret = (PPSXPROCESSINFO)PspGetPicoProcessContext(proc); \
        else \
            ret = (PPSXPROCESSINFO)PsGetProcessWin32Process(proc); \
    }

#define LxpProcessGetProcessContext(proc, new, old) \
    { \
        if (x->PicoCreated) \
            PspSetPicoProcessContext(proc, new, old); \
        else \
            PsSetProcessWin32Process(proc, new, old); \
    }

#define LxpProcessGetThreadContext(thd, ret) \
    { \
        if (x->PicoCreated) \
            ret = (PPSXTHREADINFO)PspGetPicoThreadContext(thd); \
        else \
            ret = (PPSXTHREADINFO)PPsGetThreadWin32Thread(thd); \
    }

#define LxpProcessSetThreadContext(thd, new, old) \
    { \
        if (x->PicoCreated) \
            PspSetPicoThreadContext(thd, new); \
        else \
            PsSetThreadWin32Thread(thd, new, old); \
    }
#else
#define LxpProcessGetProcessContext(proc, ret) ret = PsGetProcessWin32Process(proc);
#define LxpProcessSetProcessContext(proc, new, old) PsSetProcessWin32Process(proc, new, old);
#define LxpProcessGetThreadContext(thd, ret) ret = PsGetThreadWin32Thread(thd);
#define LxpProcessSetThreadContext(thd, r) PsSetThreadWin32Thread(thd, new, old);
#endif

#if NTDDI_VERSION >= NTDDI_WINTHRESHOLD
NTSTATUS
NTAPI
LxpPicoInitialize(VOID);
#endif

// lxcore from ms doesn't have ss support, this is specific!

NTSTATUS
NTAPI
LxpSsInitialize(VOID);
