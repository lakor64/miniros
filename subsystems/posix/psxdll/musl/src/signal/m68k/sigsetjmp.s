.set _sigsetjmp, sigsetjmp
.global _sigsetjmp
.set ___sigsetjmp, __sigsetjmp
.global ___sigsetjmp
sigsetjmp:
__sigsetjmp:
	move.l 8(%sp),%d0
	beq 1f

	movea.l 4(%sp),%a1
	move.l (%sp)+,156(%a1)
	move.l %a2,156+4+8(%a1)
	movea.l %a1,%a2

	lea ___setjmp-.-8,%a1
	jsr (%pc,%a1)

	move.l 156(%a2),-(%sp)
	move.l %a2,4(%sp)
	move.l %d0,8(%sp)
	movea.l 156+4+8(%a2),%a2

	lea __sigsetjmp_tail-.-8,%a1
	jmp (%pc,%a1)

1:	lea ___setjmp-.-8,%a1
	jmp (%pc,%a1)
