.set _vfork, vfork
.global _vfork
vfork:
	pop %rdx
	mov $58,%eax
	syscall
	push %rdx
	mov %rax,%rdi
		jmp __syscall_ret
