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
	l.lwz	r3, 0(r3)
	l.sfeqi	r3, 0
	l.bnf	__cp_cancel
	 l.ori	r11, r4, 0
	l.ori	r3, r5, 0
	l.ori	r4, r6, 0
	l.ori	r5, r7, 0
	l.ori	r6, r8, 0
	l.lwz	r7, 0(r1)
	l.lwz	r8, 4(r1)
	l.sys	1
__cp_end:
	l.jr	r9
	 l.nop
__cp_cancel:
	l.j	__cancel
	 l.nop
