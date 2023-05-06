	.set ____setjmp, ___setjmp
.global ____setjmp
		.set ___setjmp, __setjmp
.global ___setjmp
	.set __setjmp, _setjmp
.global __setjmp
	.set _setjmp, setjmp
.global _setjmp
			___setjmp:
__setjmp:
_setjmp:
setjmp:
	stmg %r6, %r15, 0(%r2)

	std  %f8,  10*8(%r2)
	std  %f9,  11*8(%r2)
	std  %f10, 12*8(%r2)
	std  %f11, 13*8(%r2)
	std  %f12, 14*8(%r2)
	std  %f13, 15*8(%r2)
	std  %f14, 16*8(%r2)
	std  %f15, 17*8(%r2)

	lghi %r2, 0
	br   %r14
