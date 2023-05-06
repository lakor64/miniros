	.set ___cp_begin, __cp_begin
.global ___cp_begin
		.set ___cp_end, __cp_end
.global ___cp_end
		.set ___cp_cancel, __cp_cancel
.global ___cp_cancel
			.set ___syscall_cp_asm, __syscall_cp_asm
.global ___syscall_cp_asm
		.text
	__syscall_cp_asm:
__cp_begin:
	icm %r2, 15, 0(%r2)
	jne __cp_cancel

	stg %r6, 48(%r15)
	stg %r7, 56(%r15)
	lgr %r1, %r3
	lgr %r2, %r4
	lgr %r3, %r5
	lgr %r4, %r6
	lg  %r5, 160(%r15)
	lg  %r6, 168(%r15)
	lg  %r7, 176(%r15)
	svc 0

__cp_end:
	lg  %r7, 56(%r15)
	lg  %r6, 48(%r15)
	br  %r14

__cp_cancel:
	jg  __cancel
