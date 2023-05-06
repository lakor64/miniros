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

__cp_begin:
	mov.l @r4, r4
	tst   r4, r4
	bf    __cp_cancel
	mov   r5, r3
	mov   r6, r4
	mov   r7, r5
	mov.l @r15, r6
	mov.l @(4,r15), r7
	mov.l @(8,r15), r0
	mov.l @(12,r15), r1
	trapa #31

__cp_end:
	! work around hardware bug
	or   r0, r0
	or   r0, r0
	or   r0, r0
	or   r0, r0
	or   r0, r0

	rts
	 nop

__cp_cancel:
	mov.l 2f, r0
	braf  r0
	 nop
1:

.align 2
2:	.long __cancel@PCREL-(1b-.)
