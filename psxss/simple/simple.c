/* Native Headers */
#define WIN32_NO_STATUS
#include <windef.h>
#include <winbase.h>
#include <winreg.h>

#define NTOS_MODE_USER
#include <ndk/iofuncs.h>
#include <ndk/obfuncs.h>
#include <ndk/rtlfuncs.h>
#include <ndk/cmfuncs.h>
#include <ndk/exfuncs.h>
#include <ndk/mmfuncs.h>
#include <ndk/psfuncs.h>
#include <ndk/lpcfuncs.h>
#include <ndk/setypes.h>
#include <ndk/umfuncs.h>
#include <ndk/kefuncs.h>

#include <ntstrsafe.h>

#include <reactos/debug.h>

#include <nt/syscalls.h>

void _start()
{
    DPRINT1("simple app start");
    //const char msg[] = "Hello from POSIX userland!";
	//sys_write(1, msg, sizeof(msg)-1);
}
