.set _sigsetjmp, sigsetjmp
.global _sigsetjmp
.set ___sigsetjmp, __sigsetjmp
.global ___sigsetjmp
sigsetjmp:
__sigsetjmp:
	bnez a1, 1f
	tail setjmp
1:

	sd ra, 208(a0)
	sd s0, 224(a0)
	mv s0, a0

	call setjmp

	mv a1, a0
	mv a0, s0
	ld s0, 224(a0)
	ld ra, 208(a0)

	tail __sigsetjmp_tail
