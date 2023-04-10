/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux core compatibility layer
 * FILE:            lxcore/pch.h
 * PURPOSE:         Standard precompilation header
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#pragma once

#define STRICT 1

#ifndef POSIXAPI
#define POSIXAPI __cdecl
#endif

/* DDK/NDK/SDK headers */
#undef NTDDI_VERSION
#define NTDDI_VERSION NTDDI_WS03SP1
#include <ntifs.h>
#include <ntddmou.h>
#include <ndk/exfuncs.h>
#include <ndk/iofuncs.h>
#include <ndk/kdfuncs.h>
#include <ndk/kefuncs.h>
#include <ndk/mmfuncs.h>
#include <ndk/obfuncs.h>
#include <ndk/psfuncs.h>
#include <ndk/sefuncs.h>
#include <ndk/rtlfuncs.h>
#include <ntstrsafe.h>
#include <ntintsafe.h>
#include <ntddkbd.h>
#include <reactos/debug.h>

/* POSIX headers */
#include <psx/types.h>
#include <psx/process.h>
#include <psx/lxcore.h>

/* Allocation tags */
#define PSXFD_TAG 'dFxP'
