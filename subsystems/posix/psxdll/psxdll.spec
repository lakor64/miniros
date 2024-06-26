# psxdll.dll 5.0.2145.1 exports
#@ stdcall GetProcessHeap()
@ stdcall HeapAlloc(ptr long ptr) ntdll.RtlAllocateHeap
@ stdcall HeapFree(long long long) ntdll.RtlFreeHeap
@ stdcall HeapReAlloc(long long ptr long) ntdll.RtlReAllocateHeap
@ stdcall HeapSize(long long ptr) ntdll.RtlSizeHeap
@ stdcall RtlAnsiCharToUnicodeChar(ptr) ntdll.RtlAnsiCharToUnicodeChar
@ stdcall RtlFillMemory(ptr long long) ntdll.RtlFillMemory
@ stdcall RtlMoveMemory(ptr ptr long) ntdll.RtlMoveMemory
@ stdcall RtlMultiByteToUnicodeN(ptr long ptr ptr long) ntdll.RtlMultiByteToUnicodeN
@ stdcall RtlUnicodeToMultiByteN(ptr long ptr ptr long) ntdll.RtlUnicodeToMultiByteN
@ stdcall RtlUnicodeToMultiByteSize(ptr ptr long) ntdll.RtlUnicodeToMultiByteSize
@ stdcall RtlUnwind(ptr ptr ptr ptr) ntdll.RtlUnwind
@ stdcall RtlUpcaseUnicodeChar(long) ntdll.RtlUpcaseUnicodeChar
@ stdcall RtlUpcaseUnicodeToMultiByteN(ptr long ptr ptr long) ntdll.RtlUpcaseUnicodeToMultiByteN
@ stdcall RtlZeroMemory(ptr long) ntdll.RtlZeroMemory
#@ stdcall __PdxGetCmdLine()
#@ stdcall __PdxInitializeData(long long)
#@ cdecl _exit(long)
#@ cdecl _sigjmp_store_mask(ptr long)
#@ cdecl access(str long)
#@ cdecl alarm(long)
#@ cdecl cfgetispeed(ptr)
#@ cdecl cfgetospeed(ptr)
#@ cdecl cfsetispeed(ptr long)
#@ cdecl cfsetospeed(ptr long)
#@ cdecl chdir(str)
#@ cdecl chmod(str long)
#@ cdecl chown(str long long)
#@ cdecl close(long)
#@ cdecl closedir(ptr)
#@ cdecl creat(str long)
#@ cdecl ctermid(str)
#@ cdecl cuserid(str)
#@ cdecl dup(long)
#@ cdecl dup2(long long)
#@varargs execl(str str)
#@varargs execle(str str)
#@varargs execlp(str str)
#@ cdecl execv(str ptr)
#@ cdecl execve(str ptr ptr)
#@ cdecl execvp(str ptr)
#@varargs fcntl(long long)
#@ cdecl fileno(ptr)
#@ cdecl fork()
#@ cdecl fpathconf(long long)
#@ cdecl fstat(long ptr)
#@ cdecl ftruncate(long long)
#@ cdecl getcwd(str long)
#@ cdecl getegid()
#@ cdecl getenv(str)
#@ cdecl geteuid()
#@ cdecl getgid()
#@ cdecl getgrgid(long)
#@ cdecl getgrnam(str)
#@ cdecl getgroups(long ptr)
#@ cdecl getlogin()
#@ cdecl getpgrp()
#@ cdecl getpid()
#@ cdecl getppid()
#@ cdecl getpwnam(str)
#@ cdecl getpwuid(long)
#@ cdecl getreg
#@ cdecl getuid()
#@ cdecl isatty(long)
#@ cdecl isatty2(long)
#@ cdecl kill(long long)
#@ cdecl link(str str)
#@ cdecl lseek(long long long)
#@ cdecl mkdir(ptr long)
#@ cdecl mkfifo(str long)
#@varargs open(str long)
#@ cdecl opendir(str)
#@ cdecl pathconf(str long)
#@ cdecl pause()
#@ cdecl pipe(ptr)
#@ cdecl raise(long)
#@ cdecl read(long ptr long)
#@ cdecl readdir(ptr)
#@ cdecl remove(str)
#@ cdecl rename(str str)
#@ cdecl rewinddir(ptr)
#@ cdecl rmdir(str)
#@ cdecl setgid(long)
#@ cdecl setpgid(long long)
#@ cdecl setsid()
#@ cdecl setuid(long)
#@ cdecl sigaction(long ptr ptr)
#@ cdecl sigaddset(ptr long)
#@ cdecl sigdelset(ptr long)
#@ cdecl sigemptyset(ptr)
#@ cdecl sigfillset(ptr)
#@ cdecl sigismember(ptr long)
#@ cdecl siglongjmp(long ptr)
#@ cdecl signal(long ptr)
#@ cdecl sigpending(ptr)
#@ cdecl sigprocmask(long ptr ptr)
#@ cdecl sigsuspend(ptr)
#@ cdecl sleep(long)
#@ cdecl stat(str ptr)
#@ cdecl sysconf(long)
#@ cdecl system(ptr)
#@ cdecl tcdrain(long)
#@ cdecl tcflow(long long)
#@ cdecl tcflush(long long)
#@ cdecl tcgetattr(long ptr)
#@ cdecl tcgetpgrp(long)
#@ cdecl tcsendbreak(long long)
#@ cdecl tcsetattr(long long ptr)
#@ cdecl tcsetpgrp(long long)
#@ cdecl time(ptr)
#@ cdecl times(long)
#@ cdecl ttyname(long)
#@ cdecl umask(long)
#@ cdecl uname(ptr)
#@ cdecl unlink(str)
#@ cdecl utime(str ptr)
#@ cdecl wait(ptr)
#@ cdecl waitpid(long ptr long)
@ cdecl write(long ptr long)

# New exports from Linux (TODO: sort this)
#@ cdecl cfmakeraw(ptr)
#@ cdecl cfsetspeed(ptr long)
#@ cdecl lstat(str ptr)
#@ cdecl longjmp(ptr long)
#@ cdecl _Exit(long)
#@ cdecl readdir_r(ptr ptr ptr)
#@ cdecl pipe2(ptr long)
#@ cdecl fdopendir(long)
#@varargs openat(long str long)
#@ cdecl ferror(ptr)
#@ cdecl feof(ptr)
#@ cdecl clearerr(ptr)
#@ cdecl setgroups(long ptr)
#@ cdecl getgrnam_r(str ptr str long ptr)
#@ cdecl getgrgid_r(long ptr str long ptr)
#@ cdecl secure_getenv(str)

# aio.h
#@ cdecl aio_read(ptr)
#@ cdecl aio_write(ptr)
#@ cdecl aio_return(ptr)
#@ cdecl aio_cancel(long ptr)
#@ cdecl aio_suspent(ptr long ptr)
#@ cdecl aio_fsync(long ptr)
#@ cdecl lio_listio(long ptr long ptr)

# alloca.h
#@ cdecl alloca(long)

# assert.h
#@ cdecl __assert_fail(ptr ptr long ptr) 

# complex.h
#@ cdecl cacos(double)
#@ cdecl cacosf(float)
#@ cdecl cacosl(double)
#@ cdecl casin(double)
#@ cdecl casinf(float)
#@ cdecl casinl(double)
#@ cdecl catan(double)
#@ cdecl catanf(double)
#@ cdecl ccos(double)
#@ cdecl ccosf(float)
#@ cdecl ccosl(double)

# New from unistd.h
#@ cdecl posix_close(long long)
#@ cdecl dup3(long long long)
#@ cdecl fsync(long)
#@ cdecl fdatasync(long)
#@ cdecl pread(long ptr long long)
#@ cdecl pwrite(long ptr long long)
#@ cdecl fchown(long long long)
#@ cdecl lchown(str long lon)
#@ cdecl fchownat(long str long long long)
#@ cdecl linkat(long str long str long)
#@ cdecl symlink(str str)
#@ cdecl symlinkat(str long str)
#@ cdecl readlink(str str long)
#@ cdecl readlinkat(long str str long)
#@ cdecl unlinkat(long str long)
#@ cdecl truncate(long long)
#@ cdecl faccessat(long str long long)
#@ cdecl fchdir(long)
#@ cdecl _Fork()
#@ cdecl fexecve(long long long)
#@ cdecl getpgid(long)
#@ cdecl getsid(long)
#@ cdecl ttyname_r(long str long)
#@ cdecl seteuid(long)
#@ cdecl setegid(long)
#@ cdecl getlogin_r(str long)
#@ cdecl gethostname(str long)
#@ cdecl getopt(long ptr str)
#@ cdecl confstr(long str long)
#@ cdecl setreuid(long long)
#@ cdecl setregid(long long)
#@ cdecl gethostid()
#@ cdecl lockf(long long long)
#@ cdecl nice(long)
#@ cdecl sync()
#@ cdecl setpgrp()
#@ cdecl crypt(str str)
#@ cdecl encrypt(str long)
#@ cdecl swab(ptr ptr long)
#@ cdecl usleep(long)
#@ cdecl ualarm(long long)
#@ cdecl brk(ptr)
#@ cdecl sbrk(ptr)
#@ cdecl vfork()
#@ cdecl vhangupo()
#@ cdecl chroot(str)
#@ cdecl getpagesize()
#@ cdecl getdtablesize()
#@ cdecl sethostname(str long)
#@ cdecl getdomainname(str long)
#@ cdecl setdomainname(str long)
#@ cdecl setgroups(long ptr)
#@ cdecl getpass(str)
#@ cdecl daemon(long long)
#@ cdecl setusershell()
#@ cdecl endusershell()
#@ cdecl getusershell()
#@ cdecl acct(str)
#@varargs syscall(long)
#@ cdecl execvpe(str ptr ptr)
#@ cdecl issetugid()
#@ cdecl getentropy(ptr long)
#@ cdecl setresuid(long long long)
#@ cdecl setresgid(long long long)
#@ cdecl getresuid(ptr ptr ptr)
#@ cdecl getresgid(ptr ptr ptr)
#@ cdecl get_current_dir_name()
#@ cdecl syncfs(long)
#@ cdecl euidaccess(str long)
#@ cdecl eaccess(str long)
#@ cdecl copy_file_range(long ptr long ptr long long)
#@ cdecl gettid()

# New from wait.h
#@ cdecl waitid(long long ptr long)
#@ cdecl wait3(ptr long ptr)
#@ cdecl wait4(long ptr long ptr)

# New from time.h
#@ cdecl gettimeofday(ptr ptr)
#@ cdecl getitimer(long ptr)
#@ cdecl setitimer(long ptr ptr)
#@ cdecl utimes(str ptr)
#@ cdecl futimes(long ptr)
#@ cdecl futimesat(long str ptr)
#@ cdecl lutimes(str ptr)
#@ cdecl settimeofday(ptr ptr)
#@ cdecl adjtime(ptr ptr)
