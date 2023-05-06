.set _vfork, vfork
.global _vfork
vfork:
	pop %rdx
	mov $0x4000003a,%eax /* SYS_vfork */
	syscall
	push %rdx
	mov %rax,%rdi
		jmp __syscall_ret
