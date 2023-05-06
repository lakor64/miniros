.set _vfork, vfork
.global _vfork
vfork:
	pop %edx
	mov $190,%eax
	int $128
	push %edx
	push %eax
		call __syscall_ret
	pop %edx
	ret
