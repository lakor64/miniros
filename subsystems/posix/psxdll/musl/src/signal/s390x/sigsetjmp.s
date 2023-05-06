	.set _sigsetjmp, sigsetjmp
.global _sigsetjmp
	.set ___sigsetjmp, __sigsetjmp
.global ___sigsetjmp
			sigsetjmp:
__sigsetjmp:
	ltgr  %r3, %r3
	jz    ___setjmp

	stg   %r14, 18*8(%r2)
	stg   %r6,  20*8(%r2)
	lgr   %r6,  %r2

	brasl %r14, ___setjmp

	lgr   %r3,  %r2
	lgr   %r2,  %r6
	lg    %r14, 18*8(%r2)
	lg    %r6,  20*8(%r2)

	jg __sigsetjmp_tail
