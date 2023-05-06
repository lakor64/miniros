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
	mov 4(%esp),%ecx
	pushl %ebx
	pushl %esi
	pushl %edi
	pushl %ebp
__cp_begin:
	movl (%ecx),%eax
	testl %eax,%eax
	jnz __cp_cancel
	movl 24(%esp),%eax
	movl 28(%esp),%ebx
	movl 32(%esp),%ecx
	movl 36(%esp),%edx
	movl 40(%esp),%esi
	movl 44(%esp),%edi
	movl 48(%esp),%ebp
	int $128
__cp_end:
	popl %ebp
	popl %edi
	popl %esi
	popl %ebx
	ret
__cp_cancel:
	popl %ebp
	popl %edi
	popl %esi
	popl %ebx
	jmp ___cancel
