	.set _sigsetjmp, sigsetjmp
.global _sigsetjmp
	.set ___sigsetjmp, __sigsetjmp
.global ___sigsetjmp
		sigsetjmp:
__sigsetjmp:
	cmpwi cr7, 4, 0
	beq- cr7, 1f

	mflr 5
	stw 5, 448(3)
	stw 16, 448+4+8(3)
	mr 16, 3

	bl ___setjmp

	mr 4, 3
	mr 3, 16
	lwz 5, 448(3)
	mtlr 5
	lwz 16, 448+4+8(3)

	b __sigsetjmp_tail

1:	b ___setjmp
