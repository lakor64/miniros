.set _sigsetjmp, sigsetjmp
.global _sigsetjmp
.set ___sigsetjmp, __sigsetjmp
.global ___sigsetjmp
sigsetjmp:
__sigsetjmp:
	l.sfeq	r4, r0
	l.bf	___setjmp

	l.sw    52(r3), r9
	l.sw    52+4+8(r3), r20

	l.jal	___setjmp
	 l.ori   r20, r3, 0

	l.ori r4, r11, 0
	l.ori r3, r20, 0

	l.lwz   r9, 52(r3)

	l.j	__sigsetjmp_tail
	 l.lwz   r20, 52+4+8(r3)
