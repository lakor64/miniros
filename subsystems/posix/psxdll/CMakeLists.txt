# Simple macro that runs the sed commands per line in the specified
#  ALLTYPES_H input and writes file to ALLTYPES_OUT
macro(alltypes_patch)
    foreach(STR IN LISTS ALLTYPES_H)
        string(REGEX REPLACE "^TYPEDEF (.*) ([^ ]*);$" "#if defined( __NEED_\\2) && !defined( __DEFINED_\\2)\ntypedef \\1 \\2;\n#define __DEFINED_\\2\n#endif\n" STR_PATCH "${STR}")
        string(REGEX REPLACE "^STRUCT * ([^ ]*) (.*);$" "#if defined( __NEED_struct_\\1) && !defined(__DEFINED_struct_\\1)\nstruct \\1 \\2;\n#define __DEFINED_struct_\\1\n#endif\n" STR_PATCH2 "${STR_PATCH}")
        string(REGEX REPLACE "^UNION * ([^ ]*) (.*);$" "#if defined(__NEED_union_\\1) && !defined(__DEFINED_union_\\1)\nunion \\1 \\2;\n#define __DEFINED_union_\\1\n#endif\n" STR_PATCH3 "${STR_PATCH2}")

        file(APPEND ${ALLTYPES_OUT} "${STR_PATCH3}\n")
    endforeach()
endmacro()

# Runs the relative of "sed" for musl types generation and writes the specific
#  files inside ${MUSL_GEN}, takes input from ${MUSL_ROOT}
# @param ARCH Target architecture
function(run_arch_sed_gen ARCH)
    # alltypes.h
    set(ALLTYPES_OUT "${MUSL_GEN}/bits/alltypes.h")
    file(REMOVE "${ALLTYPES_OUT}")
    file(STRINGS ${MUSL_ROOT}/arch/${ARCH}/bits/alltypes.h.in ALLTYPES_H)
    alltypes_patch()
    file(STRINGS ${MUSL_ROOT}/include/alltypes.h.in ALLTYPES_H)
    alltypes_patch()

    # syscall.h
    file(READ ${MUSL_ROOT}/arch/${ARCH}/bits/syscall.h.in SYSCALL_H)
    string(REPLACE "__NR_" "SYS_" SYSCALL_OUT "${SYSCALL_H}")
    file(WRITE "${MUSL_GEN}/bits/syscall.h" ${SYSCALL_OUT})
endfunction()

# Generates version.h
# Input from ${MUSL_ROOT}, output to ${MUSL_GEN}
function(gen_version)
    file(READ ${MUSL_ROOT}/VERSION VERSION_H)
    string(STRIP "${VERSION_H}" VERSION_H)
    file(WRITE ${MUSL_GEN}/version.h "#define VERSION \"${VERSION_H}\"\n")
endfunction()

set(MUSL_ROOT ${CMAKE_CURRENT_LIST_DIR}/musl)
set(MUSL_GEN ${CMAKE_BINARY_DIR}/musl)
set(MUSL_ARCH i386) # TODO: never...

# generation steps of musl makefile
run_arch_sed_gen(${MUSL_ARCH})
gen_version()

# Disable errors that kills the build
add_compile_options(-Wno-error=parentheses)
add_compile_options(-Wno-error=unused-but-set-variable)
add_compile_options(-Wno-error=format-extra-args)
add_compile_options(-Wno-error=builtin-declaration-mismatch)
add_compile_options(-Wno-error=format=)
add_compile_options(-Wno-error=old-style-declaration)
add_compile_options(-Wno-error=attributes)
add_compile_options(-Wno-error=missing-braces)
add_compile_options(-Wno-error=unknown-pragmas)
add_compile_options(-Wno-error=format-contains-nul)
add_compile_options(-Wno-error=overflow)
add_compile_options(-Wno-error=dangling-else)
add_compile_options(-Wno-error=unused-function)

# From makefile, Open/GCC source defs
add_definitions(-D_XOPEN_SOURCE=700)

# Musl specific inclusions to prioritize this files, must be kept in THIS EXACT ORDER or musl will not compile
include_directories(BEFORE ${MUSL_ROOT}/include ${MUSL_ROOT}/src/internal ${MUSL_ROOT}/src/include ${MUSL_ROOT}/arch/generic ${MUSL_GEN} ${MUSL_ROOT}/arch/${MUSL_ARCH})

spec2def(psxdll.dll psxdll.spec ADD_IMPORTLIB)

## ------------------------------------------------------------
## BEGIN OF MUSL SOURCE

set(MODULES aio complex conf crypt ctyupe dirent env errno exit fcntl fenv internal ipc ldso legacy locale linux malloc math misc mman mq multibyte network passwd prng process regex sched search select setjmp signal stat stdio stdlib string temp termios thread time unistd)
set(aio_SRC aio.c aio_suspend.c lio_listio.c)
set(complex_SRC cabs.c cabsf.c cabsl.c cacos.c cacosf.c cacosh.c cacoshf.c cacoshl.c cacosl.c carg.c cargf.c cargl.c casin.c casinf.c casinh.c casinhf.c casinhl.c casinl.c catan.c catanf.c catanh.c catanhf.c catanhl.c catanl.c ccos.c ccosf.c ccosh.c ccoshf.c ccoshl.c ccosl.c cexp.c cexpf.c cexpl.c cimag.c cimagf.c cimagl.c clog.c clogf.c clogl.c conj.c conjf.c conjl.c cpow.c cpowf.c cpowl.c cproj.c cprojf.c cprojl.c creal.c crealf.c creall.c csin.c csinf.c csinh.c csinhf.c csinhl.c csinl.c csqrt.c csqrtf.c csqrtl.c ctan.c ctanf.c ctanh.c ctanhf.c ctanhl.c ctanl.c __cexp.c __cexpf.c)
set(conf_SRC confstr.c fpathconf.c legacy.c pathconf.c sysconf.c)
set(crypt_SRC crypt.c crypt_blowfish.c crypt_des.c crypt_des.h crypt_md5.c crypt_r.c crypt_sha256.c crypt_sha512.c encrypt.c)
set(ctype_SRC isalnum.c isalpha.c isascii.c isblank.c iscntrl.c isdigit.c isgraph.c islower.c isprint.c ispunct.c isspace.c isupper.c iswalnum.c iswalpha.c iswblank.c iswcntrl.c iswctype.c iswdigit.c iswgraph.c iswlower.c iswprint.c iswpunct.c iswspace.c iswupper.c iswxdigit.c isxdigit.c toascii.c tolower.c toupper.c towctrans.c wcswidth.c wctrans.c wcwidth.c __ctype_b_loc.c __ctype_get_mb_cur_max.c __ctype_tolower_loc.c __ctype_toupper_loc.c)
set(dirent_SRC alphasort.c closedir.c dirfd.c fdopendir.c opendir.c readdir.c readdir_r.c rewinddir.c scandir.c seekdir.c telldir.c versionsort.c)
set(env_SRC clearenv.c getenv.c putenv.c secure_getenv.c setenv.c unsetenv.c __environ.c __init_tls.c __libc_start_main.c __reset_tls.c __stack_chk_fail.c)
set(errno_SRC __errno_location.c strerror.c)
set(exit_SRC abort.c abort_lock.c assert.c atexit.c at_quick_exit.c exit.c quick_exit.c _Exit.c)
set(fcntl_SRC creat.c fcntl.c open.c openat.c posix_fadvise.c posix_fallocate.c)
set(fenv_SRC __flt_rounds.c fegetexceptflag.c feholdexcept.c fesetexceptflag.c fesetround.c feupdateenv.c)
set(internal_SRC syscall_ret.c floatscan.c intscan.c libc.c procfdname.c shgetc.c vdso.c version.c)
set(ipc_SRC ftok.c msgctl.c msgget.c msgrcv.c msgsnd.c semctl.c semget.c semop.c semtimedop.c shmat.c shmctl.c shmdt.c shmget.c)
set(ldso_SRC dladdr.c dlclose.c dlerror.c dlinfo.c dlopen.c dlsym.c dl_iterate_phdr.c tlsdesc.c __dlsym.c)
set(locale_SRC bind_textdomain_codeset.c catclose.c catgets.c catopen.c c_locale.c dcngettext.c duplocale.c freelocale.c iconv.c iconv_close.c langinfo.c localeconv.c locale_map.c newlocale.c pleval.c setlocale.c strcoll.c strfmon.c strtod_l.c strxfrm.c textdomain.c uselocale.c wcscoll.c wcsxfrm.c __lctrans.c __mo_lookup.c)
set(linux_SRC adjtime.c adjtimex.c arch_prctl.c brk.c cache.c cap.c chroot.c clock_adjtime.c clone.c copy_file_range.c epoll.c eventfd.c fallocate.c fanotify.c flock.c getdents.c getrandom.c gettid.c inotify.c ioperm.c iopl.c klogctl.c membarrier.c memfd_create.c mlock2.c module.c mount.c name_to_handle_at.c open_by_handle_at.c personality.c pivot_root.c ppoll.c prctl.c prlimit.c process_vm.c ptrace.c quotactl.c readahead.c reboot.c remap_file_pages.c sbrk.c sendfile.c setfsgid.c setfsuid.c setgroups.c sethostname.c setns.c settimeofday.c signalfd.c splice.c stime.c swap.c syncfs.c sync_file_range.c sysinfo.c tee.c timerfd.c unshare.c utimes.c vhangup.c vmsplice.c wait3.c wait4.c xattr.c)
set(malloc_SRC mallocng/aligned_alloc.c mallocng/donate.c mallocng/free.c mallocng/malloc.c mallocng/malloc_usable_size.c mallocng/realloc.c calloc.c free.c libc_calloc.c lite_malloc.c memalign.c posix_memalign.c realloc.c reallocarray.c replaced.c)
#set(math_SRC acos.c acosf.c acosh.c acoshf.c acoshl.c acosl.c asin.c asinf.c asinh.c asinhf.c asinhl.c asinl.c atan.c atan2.c atan2f.c atan2l.c atanf.c atanh.c atanhf.c atanhl.c atanl.c cbrt.c cbrtf.c cbrtl.c ceil.c ceilf.c ceill.c copysign.c copysignf.c copysignl.c cos.c cosf.c cosh.c coshf.c coshl.c cosl.c erf.c erff.c erfl.c exp.c exp10.c exp10f.c exp10l.c exp2.c exp2f.c exp2f_data.c exp2l.c expf.c expl.c expm1.c expm1f.c expm1l.c exp_data.c fabs.c fabsf.c fabsl.c fdim.c fdimf.c fdiml.c finite.c finitef.c floor.c floorf.c floorl.c fma.c fmaf.c fmal.c fmax.c fmaxf.c fmaxl.c fmin.c fminf.c fminl.c fmod.c fmodf.c fmodl.c frexp.c frexpf.c frexpl.c hypot.c hypotf.c hypotl.c ilogb.c ilogbf.c ilogbl.c j0.c j0f.c j1.c j1f.c jn.c jnf.c ldexp.c ldexpf.c ldexpl.c lgamma.c lgammaf.c lgammaf_r.c lgammal.c lgamma_r.c llrint.c llrintf.c llrintl.c llround.c llroundf.c llroundl.c log.c log10.c log10f.c log10l.c log1p.c log1pf.c log1pl.c log2.c log2f.c log2f_data.c log2l.c log2_data.c logb.c logbf.c logbl.c logf.c logf_data.c logl.c log_data.c lrint.c lrintf.c lrintl.c lround.c lroundf.c lroundl.c modf.c modff.c modfl.c nan.c nanf.c nanl.c nearbyint.c nearbyintf.c nearbyintl.c nextafter.c nextafterf.c nextafterl.c nexttoward.c nexttowardf.c nexttowardl.c pow.c powf.c powf_data.c powl.c pow_data.c remainder.c remainderf.c remainderl.c remquo.c remquof.c remquol.c rint.c rintf.c rintl.c round.c roundf.c roundl.c scalb.c scalbf.c scalbln.c scalblnf.c scalblnl.c scalbn.c scalbnf.c scalbnl.c signgam.c significand.c significandf.c sin.c sincos.c sincosf.c sincosl.c sinf.c sinh.c sinhf.c sinhl.c sinl.c sqrt.c sqrtf.c sqrtl.c sqrt_data.c tan.c tanf.c tanh.c tanhf.c tanhl.c tanl.c tgamma.c tgammaf.c tgammal.c trunc.c truncf.c truncl.c __cos.c __cosdf.c __cosl.c __expo2.c __expo2f.c __fpclassify.c __fpclassifyf.c __fpclassifyl.c __invtrigl.c __math_divzero.c __math_divzerof.c __math_invalid.c __math_invalidf.c __math_invalidl.c __math_oflow.c __math_oflowf.c __math_uflow.c __math_uflowf.c __math_xflow.c __math_xflowf.c __polevll.c __rem_pio2.c __rem_pio2f.c __rem_pio2l.c __rem_pio2_large.c __signbit.c __signbitf.c __signbitl.c __sin.c __sindf.c __sinl.c __tan.c __tandf.c __tanl.c)
set(math_SRC_ARCH fabs.c fabsf.c fabsl.c fmod.c fmodf.c fmodl.c llrint.c llrintf.c llrintl.c lrint.c lrintf.c lrintl.c remainder.c remainderf.c remainderl.c rint.c rintf.c rintl.c sqrt.c sqrtf.c sqrtl.c)
set(misc_SRC a64l.c basename.c dirname.c ffs.c ffsl.c ffsll.c fmtmsg.c forkpty.c getauxval.c getdomainname.c getentropy.c gethostid.c getopt.c getopt_long.c getpriority.c getresgid.c getresuid.c getrlimit.c getrusage.c getsubopt.c get_current_dir_name.c initgroups.c ioctl.c issetugid.c lockf.c login_tty.c mntent.c nftw.c openpty.c ptsname.c pty.c realpath.c setdomainname.c setpriority.c setrlimit.c syscall.c syslog.c uname.c wordexp.c)
set(mman_SRC madvise.c mincore.c mlock.c mlockall.c mmap.c mprotect.c mremap.c msync.c munlock.c munlockall.c munmap.c posix_madvise.c shm_open.c)
set(mq_SRC mq_close.c mq_getattr.c mq_notify.c mq_open.c mq_receive.c mq_send.c mq_setattr.c mq_timedreceive.c mq_timedsend.c mq_unlink.c)
set(multibyte_SRC btowc.c c16rtomb.c c32rtomb.c internal.c mblen.c mbrlen.c mbrtoc16.c mbrtoc32.c mbrtowc.c mbsinit.c mbsnrtowcs.c mbsrtowcs.c mbstowcs.c mbtowc.c wcrtomb.c wcsnrtombs.c wcsrtombs.c wcstombs.c wctob.c wctomb.c)
set(network_SRC accept.c accept4.c bind.c connect.c dns_parse.c dn_comp.c dn_expand.c dn_skipname.c ent.c ether.c freeaddrinfo.c gai_strerror.c getaddrinfo.c gethostbyaddr.c gethostbyaddr_r.c gethostbyname.c gethostbyname2.c gethostbyname2_r.c gethostbyname_r.c getifaddrs.c getnameinfo.c getpeername.c getservbyname.c getservbyname_r.c getservbyport.c getservbyport_r.c getsockname.c getsockopt.c herror.c hstrerror.c htonl.c htons.c h_errno.c if_freenameindex.c if_indextoname.c if_nameindex.c if_nametoindex.c in6addr_any.c in6addr_loopback.c inet_addr.c inet_aton.c inet_legacy.c inet_ntoa.c inet_ntop.c inet_pton.c listen.c lookup_ipliteral.c lookup_name.c lookup_serv.c netlink.c netname.c ns_parse.c ntohl.c ntohs.c proto.c recv.c recvfrom.c recvmmsg.c recvmsg.c resolvconf.c res_init.c res_mkquery.c res_msend.c res_query.c res_querydomain.c res_send.c res_state.c send.c sendmmsg.c sendmsg.c sendto.c serv.c setsockopt.c shutdown.c sockatmark.c socket.c socketpair.c)
set(passwd_SRC fgetgrent.c fgetpwent.c fgetspent.c getgrent.c getgrent_a.c getgrouplist.c getgr_a.c getgr_r.c getpwent.c getpwent_a.c getpw_a.c getpw_r.c getspent.c getspnam.c getspnam_r.c lckpwdf.c nscd_query.c putgrent.c putpwent.c putspent.c)
set(prng_SRC drand48.c lcong48.c lrand48.c mrand48.c rand.c random.c rand_r.c seed48.c srand48.c __rand48_step.c __seed48.c)
set(process_SRC execl.c execle.c execlp.c execv.c execve.c execvp.c fexecve.c fork.c posix_spawn.c posix_spawnattr_destroy.c posix_spawnattr_getflags.c posix_spawnattr_getpgroup.c posix_spawnattr_getsigdefault.c posix_spawnattr_getsigmask.c posix_spawnattr_init.c posix_spawnattr_sched.c posix_spawnattr_setflags.c posix_spawnattr_setpgroup.c posix_spawnattr_setsigdefault.c posix_spawnattr_setsigmask.c posix_spawnp.c posix_spawn_file_actions_addchdir.c posix_spawn_file_actions_addclose.c posix_spawn_file_actions_adddup2.c posix_spawn_file_actions_addfchdir.c posix_spawn_file_actions_addopen.c posix_spawn_file_actions_destroy.c posix_spawn_file_actions_init.c system.c vfork.c wait.c waitid.c waitpid.c _Fork.c)
set(regex_SRC fnmatch.c glob.c regcomp.c regerror.c regexec.c tre-mem.c)
set(sched_SRC affinity.c sched_cpucount.c sched_getcpu.c sched_getparam.c sched_getscheduler.c sched_get_priority_max.c sched_rr_get_interval.c sched_setparam.c sched_setscheduler.c sched_yield.c)
set(search_SRC hsearch.c insque.c lsearch.c tdelete.c tdestroy.c tfind.c tsearch.c twalk.c)
set(select_SRC poll.c pselect.c select.c)
set(setjmp_SRC longjmp.c setjmp.c)
set(signal_SRC block.c getitimer.c kill.c killpg.c psiginfo.c psignal.c raise.c restore.c setitimer.c sigaction.c sigaddset.c sigaltstack.c sigandset.c sigdelset.c sigemptyset.c sigfillset.c sighold.c sigignore.c siginterrupt.c sigisemptyset.c sigismember.c siglongjmp.c signal.c sigorset.c sigpause.c sigpending.c sigprocmask.c sigqueue.c sigrelse.c sigrtmax.c sigrtmin.c sigset.c sigsetjmp.c sigsetjmp_tail.c sigsuspend.c sigtimedwait.c sigwait.c sigwaitinfo.c)
set(stat_SRC chmod.c fchmod.c fchmodat.c fstat.c fstatat.c futimens.c futimesat.c lchmod.c lstat.c mkdir.c mkdirat.c mkfifo.c mkfifoat.c mknod.c mknodat.c stat.c statvfs.c umask.c utimensat.c __xstat.c)
set(stdio_SRC asprintf.c clearerr.c dprintf.c ext.c ext2.c fclose.c feof.c ferror.c fflush.c fgetc.c fgetln.c fgetpos.c fgets.c fgetwc.c fgetws.c fileno.c flockfile.c fmemopen.c fopen.c fopencookie.c fprintf.c fputc.c fputs.c fputwc.c fputws.c fread.c freopen.c fscanf.c fseek.c fsetpos.c ftell.c ftrylockfile.c funlockfile.c fwide.c fwprintf.c fwrite.c fwscanf.c getc.c getchar.c getchar_unlocked.c getc_unlocked.c getdelim.c getline.c gets.c getw.c getwc.c getwchar.c ofl.c ofl_add.c open_memstream.c open_wmemstream.c pclose.c perror.c popen.c printf.c putc.c putchar.c putchar_unlocked.c putc_unlocked.c puts.c putw.c putwc.c putwchar.c remove.c rename.c rewind.c scanf.c setbuf.c setbuffer.c setlinebuf.c setvbuf.c snprintf.c sprintf.c sscanf.c stderr.c stdin.c stdout.c swprintf.c swscanf.c tempnam.c tmpfile.c tmpnam.c ungetc.c ungetwc.c vasprintf.c vdprintf.c vfprintf.c vfscanf.c vfwprintf.c vfwscanf.c vprintf.c vscanf.c vsnprintf.c vsprintf.c vsscanf.c vswprintf.c vswscanf.c vwprintf.c vwscanf.c wprintf.c wscanf.c __fclose_ca.c __fdopen.c __fmodeflags.c __fopen_rb_ca.c __lockfile.c __overflow.c __stdio_close.c __stdio_exit.c __stdio_read.c __stdio_seek.c __stdio_write.c __stdout_write.c __toread.c __towrite.c __uflow.c)
set(stdlib_SRC abs.c atof.c atoi.c atol.c atoll.c bsearch.c div.c ecvt.c fcvt.c gcvt.c imaxabs.c imaxdiv.c labs.c ldiv.c llabs.c lldiv.c qsort.c qsort_nr.c strtod.c strtol.c wcstod.c wcstol.c)
set(string_SRC bcmp.c bcopy.c bzero.c explicit_bzero.c index.c memccpy.c memchr.c memcmp.c memcpy.c memmem.c memmove.c mempcpy.c memrchr.c memset.c rindex.c stpcpy.c stpncpy.c strcasecmp.c strcasestr.c strcat.c strchr.c strchrnul.c strcmp.c strcpy.c strcspn.c strdup.c strerror_r.c strlcat.c strlcpy.c strlen.c strncasecmp.c strncat.c strncmp.c strncpy.c strndup.c strnlen.c strpbrk.c strrchr.c strsep.c strsignal.c strspn.c strstr.c strtok.c strtok_r.c strverscmp.c swab.c wcpcpy.c wcpncpy.c wcscasecmp.c wcscasecmp_l.c wcscat.c wcschr.c wcscmp.c wcscpy.c wcscspn.c wcsdup.c wcslen.c wcsncasecmp.c wcsncasecmp_l.c wcsncat.c wcsncmp.c wcsncpy.c wcsnlen.c wcspbrk.c wcsrchr.c wcsspn.c wcsstr.c wcstok.c wcswcs.c wmemchr.c wmemcmp.c wmemcpy.c wmemmove.c wmemset.c)
set(temp_SRC mkdtemp.c mkostemp.c mkostemps.c mkstemp.c mkstemps.c mktemp.c __randname.c)
set(termios_SRC cfgetospeed.c cfmakeraw.c cfsetospeed.c tcdrain.c tcflow.c tcflush.c tcgetattr.c tcgetsid.c tcgetwinsize.c tcsendbreak.c tcsetattr.c tcsetwinsize.c)
set(thread_SRC call_once.c clone.c cnd_broadcast.c cnd_destroy.c cnd_init.c cnd_signal.c cnd_timedwait.c cnd_wait.c default_attr.c lock_ptc.c mtx_destroy.c mtx_init.c mtx_lock.c mtx_timedlock.c mtx_trylock.c mtx_unlock.c pthread_atfork.c pthread_attr_destroy.c pthread_attr_get.c pthread_attr_init.c pthread_attr_setdetachstate.c pthread_attr_setguardsize.c pthread_attr_setinheritsched.c pthread_attr_setschedparam.c pthread_attr_setschedpolicy.c pthread_attr_setscope.c pthread_attr_setstack.c pthread_attr_setstacksize.c pthread_barrierattr_destroy.c pthread_barrierattr_init.c pthread_barrierattr_setpshared.c pthread_barrier_destroy.c pthread_barrier_init.c pthread_barrier_wait.c pthread_cancel.c pthread_cleanup_push.c pthread_condattr_destroy.c pthread_condattr_init.c pthread_condattr_setclock.c pthread_condattr_setpshared.c pthread_cond_broadcast.c pthread_cond_destroy.c pthread_cond_init.c pthread_cond_signal.c pthread_cond_timedwait.c pthread_cond_wait.c pthread_create.c pthread_detach.c pthread_equal.c pthread_getattr_np.c pthread_getconcurrency.c pthread_getcpuclockid.c pthread_getname_np.c pthread_getschedparam.c pthread_getspecific.c pthread_join.c pthread_key_create.c pthread_kill.c pthread_mutexattr_destroy.c pthread_mutexattr_init.c pthread_mutexattr_setprotocol.c pthread_mutexattr_setpshared.c pthread_mutexattr_setrobust.c pthread_mutexattr_settype.c pthread_mutex_consistent.c pthread_mutex_destroy.c pthread_mutex_getprioceiling.c pthread_mutex_init.c pthread_mutex_lock.c pthread_mutex_setprioceiling.c pthread_mutex_timedlock.c pthread_mutex_trylock.c pthread_mutex_unlock.c pthread_once.c pthread_rwlockattr_destroy.c pthread_rwlockattr_init.c pthread_rwlockattr_setpshared.c pthread_rwlock_destroy.c pthread_rwlock_init.c pthread_rwlock_rdlock.c pthread_rwlock_timedrdlock.c pthread_rwlock_timedwrlock.c pthread_rwlock_tryrdlock.c pthread_rwlock_trywrlock.c pthread_rwlock_unlock.c pthread_rwlock_wrlock.c pthread_self.c pthread_setattr_default_np.c pthread_setcancelstate.c pthread_setcanceltype.c pthread_setconcurrency.c pthread_setname_np.c pthread_setschedparam.c pthread_setschedprio.c pthread_setspecific.c pthread_sigmask.c pthread_spin_destroy.c pthread_spin_init.c pthread_spin_lock.c pthread_spin_trylock.c pthread_spin_unlock.c pthread_testcancel.c sem_destroy.c sem_getvalue.c sem_init.c sem_open.c sem_post.c sem_timedwait.c sem_trywait.c sem_unlink.c sem_wait.c synccall.c syscall_cp.c thrd_create.c thrd_exit.c thrd_join.c thrd_sleep.c thrd_yield.c tls.c tss_create.c tss_delete.c tss_set.c vmlock.c __lock.c __set_thread_area.c __syscall_cp.c __timedwait.c __tls_get_addr.c __unmapself.c __wait.c)
set(time_SRC asctime.c asctime_r.c clock.c clock_getcpuclockid.c clock_getres.c clock_gettime.c clock_nanosleep.c clock_settime.c ctime.c ctime_r.c difftime.c ftime.c getdate.c gettimeofday.c gmtime.c gmtime_r.c localtime.c localtime_r.c mktime.c nanosleep.c strftime.c strptime.c time.c timegm.c timer_create.c timer_delete.c timer_getoverrun.c timer_gettime.c timer_settime.c times.c timespec_get.c utime.c wcsftime.c __map_file.c __month_to_secs.c __secs_to_tm.c __tm_to_secs.c __tz.c __year_to_secs.c)
set(unistd_SRC access.c acct.c alarm.c chdir.c chown.c close.c ctermid.c dup.c dup2.c dup3.c faccessat.c fchdir.c fchown.c fchownat.c fdatasync.c fsync.c ftruncate.c getcwd.c getegid.c geteuid.c getgid.c getgroups.c gethostname.c getlogin.c getlogin_r.c getpgid.c getpgrp.c getpid.c getppid.c getsid.c getuid.c isatty.c lchown.c link.c linkat.c lseek.c nice.c pause.c pipe.c pipe2.c posix_close.c pread.c preadv.c pwrite.c pwritev.c read.c readlink.c readlinkat.c readv.c renameat.c rmdir.c setegid.c seteuid.c setgid.c setpgid.c setpgrp.c setregid.c setresgid.c setresuid.c setreuid.c setsid.c setuid.c setxid.c sleep.c symlink.c symlinkat.c sync.c tcgetpgrp.c tcsetpgrp.c truncate.c ttyname.c ttyname_r.c ualarm.c unlink.c unlinkat.c usleep.c write.c writev.c _exit.c)
set(ldso_root_SRC dlstart.c dynlink.c)
set(crt_root_SRC crt1.c crti.c crtn.c rcrt1.c)
set(crt_root_SRC_ASM crti.s crtn.s)

# ASM!
set(fenv_SRC_ASM fenv.s)
set(math_SRC_ASM acos.s acosf.s acosl.s asin.s asinf.s asinl.s atan.s atan2.s atan2f.s atan2l.s atanf.s atanl.s ceil.s ceilf.s ceill.s exp2l.s expm1l.s exp_ld.s floor.s floorf.s floorl.s hypot.s hypotf.s ldexp.s ldexpf.s ldexpl.s log.s log10.s log10f.s log10l.s log1p.s log1pf.s log1pl.s log2.s log2f.s log2l.s logf.s logl.s remquo.s remquof.s remquol.s scalbln.s scalblnf.s scalblnl.s scalbn.s scalbnf.s scalbnl.s trunc.s truncf.s truncl.s __invtrigl.s)
set(internal_SRC_ASM defsysinfo.s)
set(thread_SRC_ASM syscall_cp.s clone.s tls.s __unmapself.s __set_thread_area.s)
set(string_SRC_ASM memcpy.s memset.s memmove.s)
set(ldso_SRC_ASM dlsym.s dlsym_time64.S tlsdesc.s)
set(setjmp_SRC_ASM longjmp.s setjmp.s)
set(signal_SRC_ASM restore.s sigsetjmp.s)

foreach(M IN LISTS MODULES)
    list(TRANSFORM ${M}_SRC PREPEND "${MUSL_ROOT}/src/${M}/")
    list(TRANSFORM ${M}_SRC_ASM PREPEND "${MUSL_ROOT}/src/${M}/${MUSL_ARCH}/")
    list(TRANSFORM ${M}_SRC_ARCH PREPEND "${MUSL_ROOT}/src/${M}/${MUSL_ARCH}/")
    list(APPEND MUSL_SRC ${${M}_SRC} ${${M}_SRC_ARCH})
    list(APPEND MUSL_ASM_SRC ${${M}_SRC_ASM})
endforeach()

list(TRANSFORM ldso_root_SRC PREPEND "${MUSL_ROOT}/ldso/")
list(APPEND MUSL_SRC ${ldso_root_SRC})
list(TRANSFORM crt_root_SRC PREPEND "${MUSL_ROOT}/crt/")
list(APPEND MUSL_SRC ${crt_root_SRC})
list(TRANSFORM crt_root_SRC_ASM PREPEND "${MUSL_ROOT}/crt/${MUSL_ARCH}/")
list(APPEND MUSL_ASM_SRC ${crt_root_SRC_ASM})

## END OF MUSL SOURCE
## ------------------------------------------------------------

set(ASM_FILES ntsyscall.s)

add_asm_files(psxdll_asm ${MUSL_ASM_SRC} ${ASM_FILES})

add_library(musl STATIC
    ${MUSL_SRC}
    ${psxdll_asm}
)

add_library(psxdll SHARED
    psxdll.rc
    ${CMAKE_CURRENT_BINARY_DIR}/psxdll.def
)

set_module_type(psxdll posix ENTRYPOINT 0)
target_link_libraries(psxdll musl ${PSEH_LIB} nt)
add_importlibs(psxdll ntdll)
add_dependencies(psxdll asm)
add_cd_file(TARGET psxdll DESTINATION reactos/system32 NO_CAB FOR all)
