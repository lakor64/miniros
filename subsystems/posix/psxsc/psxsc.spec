# userland
@ stdcall -arch=i386 restart_syscall()
@ stdcall exit(long)
@ stdcall fork()
@ stdcall read(long ptr long)
@ stdcall write(long ptr long)
@ stdcall open(ptr long long)
@ stdcall close(long)

# kernelland
@ stdcall -arch=i386 sys_restart_syscall()
@ stdcall sys_exit(long)
@ stdcall sys_fork()
@ stdcall sys_read(long ptr long)
@ stdcall sys_write(long ptr long)
@ stdcall sys_open(ptr long long)
@ stdcall sys_close(long)
