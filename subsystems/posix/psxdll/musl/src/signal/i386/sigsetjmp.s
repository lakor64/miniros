.set _sigsetjmp, sigsetjmp
.global _sigsetjmp
.set ___sigsetjmp, __sigsetjmp
.global ___sigsetjmp
sigsetjmp:
__sigsetjmp:
	mov 8(%esp),%ecx
	jecxz 1f

	mov 4(%esp),%eax
	popl 24(%eax)
	mov %ebx,28+8(%eax)
	mov %eax,%ebx

	call ___setjmp

	pushl 24(%ebx)
	mov %ebx,4(%esp)
	mov %eax,8(%esp)
	mov 28+8(%ebx),%ebx

	jmp ___sigsetjmp_tail

1:	jmp ___setjmp
