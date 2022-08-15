/* TODO: this will be removed */
typedef const char* LPCSTR;
typedef const void* LPCVOID;
typedef unsigned long ULONG;
typedef long LONG_PTR;
typedef long LONG;
typedef int INT;

#include <nt/syscalls.h>

void _start()
{
    const char msg[] = "Hello from POSIX userland!";
	sys_write(1, msg, sizeof(msg)-1);
}
