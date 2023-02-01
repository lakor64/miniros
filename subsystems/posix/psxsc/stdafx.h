/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Posix syscall compatibility layer
 * FILE:            psxss/psxsc/stdafx.h
 * PURPOSE:         Standard precompilation header
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#pragma once

#define NTOS_MODE_USER
#include <ndk/umtypes.h>
#include <ndk/iotypes.h>
#include <ndk/obtypes.h>
#include <ndk/rtltypes.h>

#include <ndk/obfuncs.h>
#include <ndk/rtlfuncs.h>
#include <ndk/iofuncs.h>

#include <reactos/debug.h>

// psxss
#include <nt/syscalls.h>
