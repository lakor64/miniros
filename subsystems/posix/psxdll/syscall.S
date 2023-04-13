
#include <syscalls_psx.inc>

#ifdef _M_ARM

    TEXTAREA

#define SC_(uppername, lowername, argcount) STUB_U lowername

#include <psx/sclist.h>

    END

#else

.code

#define SC_(uppername, lowername, argcount) STUB_U lowername, argcount

#include <psx/sclist.h>

END
#endif
