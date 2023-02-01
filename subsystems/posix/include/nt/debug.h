/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         Posix syscall compatibility layer
 * FILE:            psxss/include/nt/debug.h
 * PURPOSE:         Wraps ReactOS debugging macros
 * PROGRAMMERS:     Christian Rendina (christian.rendina@gmail.com)
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

unsigned long __cdecl DbgPrint(const char* Format, ...);
unsigned long __cdecl DbgPrintEx(unsigned long ComponentID, unsigned long Level, const char* Format, ...);

/* Print stuff only on Debug Builds*/
#if DBG

    /* These are always printed */
    #define DPRINT1(fmt, ...) do { \
        if (DbgPrint("(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__))  \
            DbgPrint("(%s:%d) DbgPrint() failed!\n", __RELFILE__, __LINE__); \
    } while (0)

    /* These are printed only if NDEBUG is NOT defined */
    #ifndef NDEBUG

        #define DPRINT(fmt, ...) do { \
            if (DbgPrint("(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__))  \
                DbgPrint("(%s:%d) DbgPrint() failed!\n", __RELFILE__, __LINE__); \
        } while (0)

    #else

#if defined(_MSC_VER)
        #define DPRINT   __noop
#else
        #define DPRINT(...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
#endif

    #endif

    #define UNIMPLEMENTED         __NOTICE(WARNING, "is UNIMPLEMENTED!\n")
    #define UNIMPLEMENTED_ONCE    do { static int bWarnedOnce = 0; if (!bWarnedOnce) { bWarnedOnce++; UNIMPLEMENTED; } } while (0)

    #define ERR_(ch, fmt, ...)    DbgPrintEx(DPFLTR_##ch##_ID, DPFLTR_ERROR_LEVEL, "(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__)
    #define WARN_(ch, fmt, ...)   DbgPrintEx(DPFLTR_##ch##_ID, DPFLTR_WARNING_LEVEL, "(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__)
    #define TRACE_(ch, fmt, ...)  DbgPrintEx(DPFLTR_##ch##_ID, DPFLTR_TRACE_LEVEL, "(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__)
    #define INFO_(ch, fmt, ...)   DbgPrintEx(DPFLTR_##ch##_ID, DPFLTR_INFO_LEVEL, "(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__)

    #define ERR__(ch, fmt, ...)    DbgPrintEx(ch, DPFLTR_ERROR_LEVEL, "(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__)
    #define WARN__(ch, fmt, ...)   DbgPrintEx(ch, DPFLTR_WARNING_LEVEL, "(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__)
    #define TRACE__(ch, fmt, ...)  DbgPrintEx(ch, DPFLTR_TRACE_LEVEL, "(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__)
    #define INFO__(ch, fmt, ...)   DbgPrintEx(ch, DPFLTR_INFO_LEVEL, "(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__)

#else /* not DBG */

    /* On non-debug builds, we never show these */
    #define UNIMPLEMENTED
    #define UNIMPLEMENTED_ONCE
#if defined(_MSC_VER)
    #define DPRINT1   __noop
    #define DPRINT    __noop

    #define ERR_(ch, ...)      __noop
    #define WARN_(ch, ...)     __noop
    #define TRACE_(ch, ...)    __noop
    #define INFO_(ch, ...)     __noop

    #define ERR__(ch, ...)     __noop
    #define WARN__(ch, ...)    __noop
    #define TRACE__(ch, ...)   __noop
    #define INFO__(ch, ...)    __noop
#else
    #define DPRINT1(...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
    #define DPRINT(...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)

    #define ERR_(ch, ...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
    #define WARN_(ch, ...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
    #define TRACE_(ch, ...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
    #define INFO_(ch, ...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)

    #define ERR__(ch, ...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
    #define WARN__(ch, ...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
    #define TRACE__(ch, ...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
    #define INFO__(ch, ...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
#endif /* _MSC_VER */

#endif /* not DBG */


#ifdef __cplusplus
}
#endif
