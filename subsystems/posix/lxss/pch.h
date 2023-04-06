/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux subsystem
 * FILE:            lxss/pch.h
 * PURPOSE:         Standard precompilation header
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#pragma once

// Enable/disable lxss.sys as the replacement Kmode executor (miniros set this to 1, 0 otherwise)
#define __LNX32K__ 1

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
