/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Linux/POSIX core compatibility layer
 * FILE:            psx/types.h
 * PURPOSE:         POSIX default types
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#pragma once

#if __X64__
    typedef signed long long ssize_t;
#else
    typedef signed long ssize_t;
#endif

typedef unsigned short umode_t;
