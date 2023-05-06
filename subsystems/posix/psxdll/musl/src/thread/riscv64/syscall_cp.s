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
	lw t0, 0(a0)
	bnez t0, __cp_cancel

	mv t0, a1
	mv a0, a2
	mv a1, a3
	mv a2, a4
	mv a3, a5
	mv a4, a6
	mv a5, a7
	ld a6, 0(sp)
	mv a7, t0
	ecall
__cp_end:
	ret
__cp_cancel:
	tail __cancel
