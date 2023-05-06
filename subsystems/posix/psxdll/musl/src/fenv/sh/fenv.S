#if __SH_FPU_ANY__ || __SH4__

.set _fegetround, fegetround
.global _fegetround
fegetround:
	sts fpscr, r0
	rts
	 and #3, r0

.set ___fesetround, __fesetround
.global ___fesetround
__fesetround:
	sts fpscr, r0
	mov #-4, r1
	and r1, r0
	or  r4, r0
	lds r0, fpscr
	rts
	 mov #0, r0

.set _fetestexcept, fetestexcept
.global _fetestexcept
fetestexcept:
	sts fpscr, r0
	and r4, r0
	rts
	 and #0x7c, r0

.set _feclearexcept, feclearexcept
.global _feclearexcept
feclearexcept:
	mov r4, r0
	and #0x7c, r0
	not r0, r4
	sts fpscr, r0
	and r4, r0
	lds r0, fpscr
	rts
	 mov #0, r0

.set _feraiseexcept, feraiseexcept
.global _feraiseexcept
feraiseexcept:
	mov r4, r0
	and #0x7c, r0
	sts fpscr, r4
	or  r4, r0
	lds r0, fpscr
	rts
	 mov #0, r0

.set _fegetenv, fegetenv
.global _fegetenv
fegetenv:
	sts fpscr, r0
	mov.l r0, @r4
	rts
	 mov #0, r0

.set _fesetenv, fesetenv
.global _fesetenv
fesetenv:
	mov r4, r0
	cmp/eq #-1, r0
	bf 1f

	! the default environment is complicated by the fact that we need to
	! preserve the current precision bit, which we do not know a priori
	sts fpscr, r0
	mov #8, r1
	swap.w r1, r1
	bra 2f
	 and r1, r0

1:	mov.l @r4, r0      ! non-default environment
2:	lds r0, fpscr
	rts
	 mov #0, r0

#endif
