.set ___cp_begin, __cp_begin
.global ___cp_begin
.set ___cp_end, __cp_end
.global ___cp_end
.set ___cp_cancel, __cp_cancel
.global ___cp_cancel
.set ___syscall_cp_asm, __syscall_cp_asm
.global ___syscall_cp_asm
__syscall_cp_asm:
__cp_begin:
	lwi     r5, r5, 0
	bnei    r5, __cp_cancel
	addi    r12, r6, 0
	add     r5, r7, r0
	add     r6, r8, r0
	add     r7, r9, r0
	add     r8, r10, r0
	lwi     r9, r1, 28
	lwi     r10, r1, 32
	brki    r14, 0x8
__cp_end:
	rtsd    r15, 8
	nop
__cp_cancel:
	bri     __cancel
