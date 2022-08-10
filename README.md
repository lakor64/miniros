# miniros

This project was designed to test out the functionalities of a hypotetical POSIX subsystem for the NT kernel (powered by ReactOS), 
as well as a bedtest for developing with the NT Native Development Kit (NDK)

The scope of the subsystem is to bootup a POSIX-like environment without relying on the Windows userland subsystem (win32k.sys), by fact
this system does not load Win32k.sys, cxsrss and any other Windows userland components.

The directory "system32" has been removed (SYSTEMHIVE has been adjusted, hardcoded paths have been removed from the NT kernel) and moved to a more UNIX-like
directory structure (altrough this changes were done as a pure test on the kernel and are not required for the POSIX translation layer)

The userland POSIX translation layer (psxdll.dll) is implemented by converting POSIX calls into NT kernel relatives.

- Currently there is much to do to even show a terminal running, the project is very experimental and not designed to be used.
