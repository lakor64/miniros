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
	movea.l 4(%sp),%a0
	movem.l %d2-%d7/%a2-%a7,(%a0)
	move.l (%sp),48(%a0)
	fmovem.x %fp2-%fp7,52(%a0)
	clr.l %d0
	rts
