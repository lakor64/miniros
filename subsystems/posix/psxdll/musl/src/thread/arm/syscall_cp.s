.syntax unified
.set ___cp_begin, __cp_begin
.global ___cp_begin
.set ___cp_end, __cp_end
.global ___cp_end
.set ___cp_cancel, __cp_cancel
.global ___cp_cancel
.set ___syscall_cp_asm, __syscall_cp_asm
.global ___syscall_cp_asm
__syscall_cp_asm:
	mov ip,sp
	stmfd sp!,{r4,r5,r6,r7}
__cp_begin:
	ldr r0,[r0]
	cmp r0,#0
	bne __cp_cancel
	mov r7,r1
	mov r0,r2
	mov r1,r3
	ldmfd ip,{r2,r3,r4,r5,r6}
	svc 0
__cp_end:
	ldmfd sp!,{r4,r5,r6,r7}
	bx lr
__cp_cancel:
	ldmfd sp!,{r4,r5,r6,r7}
	b __cancel
