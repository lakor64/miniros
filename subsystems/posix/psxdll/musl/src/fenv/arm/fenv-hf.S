#if __ARM_PCS_VFP

.syntax unified
.fpu vfp

.set _fegetround, fegetround
.global _fegetround
fegetround:
	fmrx r0, fpscr
	and r0, r0, #0xc00000
	bx lr

.set ___fesetround, __fesetround
.global ___fesetround
__fesetround:
	fmrx r3, fpscr
	bic r3, r3, #0xc00000
	orr r3, r3, r0
	fmxr fpscr, r3
	mov r0, #0
	bx lr

.set _fetestexcept, fetestexcept
.global _fetestexcept
fetestexcept:
	and r0, r0, #0x1f
	fmrx r3, fpscr
	and r0, r0, r3
	bx lr

.set _feclearexcept, feclearexcept
.global _feclearexcept
feclearexcept:
	and r0, r0, #0x1f
	fmrx r3, fpscr
	bic r3, r3, r0
	fmxr fpscr, r3
	mov r0, #0
	bx lr

.set _feraiseexcept, feraiseexcept
.global _feraiseexcept
feraiseexcept:
	and r0, r0, #0x1f
	fmrx r3, fpscr
	orr r3, r3, r0
	fmxr fpscr, r3
	mov r0, #0
	bx lr

.set _fegetenv, fegetenv
.global _fegetenv
fegetenv:
	fmrx r3, fpscr
	str r3, [r0]
	mov r0, #0
	bx lr

.set _fesetenv, fesetenv
.global _fesetenv
fesetenv:
	cmn r0, #1
	moveq r3, #0
	ldrne r3, [r0]
	fmxr fpscr, r3
	mov r0, #0
	bx lr

#endif
