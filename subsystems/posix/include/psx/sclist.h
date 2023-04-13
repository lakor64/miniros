
#ifdef _M_IX86
SC_ (RESTART_SYSCALL, restart_syscall, 0)
SC_ (EXIT, exit, 1)
SC_ (FORK, fork, 0)
#endif
SC_ (READ, read, 3)
SC_ (WRITE, write, 3)
SC_ (OPEN, open, 3)
SC_ (CLOSE, close, 1)
