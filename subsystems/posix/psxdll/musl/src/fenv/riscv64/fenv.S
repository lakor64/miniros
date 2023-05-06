#ifdef __riscv_flen

.set _feclearexcept, feclearexcept
.global _feclearexcept
feclearexcept:
	csrc fflags, a0
	li a0, 0
	ret

.set _feraiseexcept, feraiseexcept
.global _feraiseexcept
feraiseexcept:
	csrs fflags, a0
	li a0, 0
	ret

.set _fetestexcept, fetestexcept
.global _fetestexcept
fetestexcept:
	frflags t0
	and a0, t0, a0
	ret

.set _fegetround, fegetround
.global _fegetround
fegetround:
	frrm a0
	ret

.set ___fesetround, __fesetround
.global ___fesetround
__fesetround:
	fsrm t0, a0
	li a0, 0
	ret

.set _fegetenv, fegetenv
.global _fegetenv
fegetenv:
	frcsr t0
	sw t0, 0(a0)
	li a0, 0
	ret

.set _fesetenv, fesetenv
.global _fesetenv
fesetenv:
	li t2, -1
	li t1, 0
	beq a0, t2, 1f
	lw t1, 0(a0)
1:	fscsr t1
	li a0, 0
	ret

#endif
