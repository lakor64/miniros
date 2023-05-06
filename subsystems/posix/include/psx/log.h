#pragma once

unsigned long
__cdecl
DbgPrint(
    const char* Format,
    ...
);


#if DBG
    #define DPRINT1(fmt, ...) do { \
        if (DbgPrint("(%s:%d) " fmt, __RELFILE__, __LINE__, ##__VA_ARGS__))  \
            DbgPrint("(%s:%d) DbgPrint() failed!\n", __RELFILE__, __LINE__); \
    } while (0)
#else

#if defined(_MSC_VER)
    #define DPRINT1   __noop
    #define DPRINT    __noop
#else
    #define DPRINT1(...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
    #define DPRINT(...) do { if(0) { DbgPrint(__VA_ARGS__); } } while(0)
#endif

#endif
