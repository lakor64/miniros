.set _sigsetjmp, sigsetjmp
.global _sigsetjmp
.set ___sigsetjmp, __sigsetjmp
.global ___sigsetjmp
sigsetjmp:
__sigsetjmp:
	cbz x1,setjmp

	str x30,[x0,#176]
	str x19,[x0,#176+8+8]
	mov x19,x0

	bl setjmp

	mov w1,w0
	mov x0,x19
	ldr x30,[x0,#176]
	ldr x19,[x0,#176+8+8]

	b __sigsetjmp_tail
