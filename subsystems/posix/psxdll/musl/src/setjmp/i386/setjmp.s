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
	mov 4(%esp), %eax
	mov    %ebx, (%eax)
	mov    %esi, 4(%eax)
	mov    %edi, 8(%eax)
	mov    %ebp, 12(%eax)
	lea 4(%esp), %ecx
	mov    %ecx, 16(%eax)
	mov  (%esp), %ecx
	mov    %ecx, 20(%eax)
	xor    %eax, %eax
	ret
