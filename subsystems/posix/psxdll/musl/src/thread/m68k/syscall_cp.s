.text
.set ___cp_begin, __cp_begin
.global ___cp_begin
.set ___cp_end, __cp_end
.global ___cp_end
.set ___cp_cancel, __cp_cancel
.global ___cp_cancel
.set ___syscall_cp_asm, __syscall_cp_asm
.global ___syscall_cp_asm
__syscall_cp_asm:
	movem.l %d2-%d5,-(%sp)
	movea.l 20(%sp),%a0
__cp_begin:
	move.l (%a0),%d0
	bne __cp_cancel
	movem.l 24(%sp),%d0-%d5/%a0
	trap #0
__cp_end:
	movem.l (%sp)+,%d2-%d5
	rts
__cp_cancel:
	movem.l (%sp)+,%d2-%d5
	move.l __cancel-.-8,%a1
	jmp (%pc,%a1)
