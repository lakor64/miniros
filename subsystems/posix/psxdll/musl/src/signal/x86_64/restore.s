	nop
.set ___restore_rt, __restore_rt
.global ___restore_rt
__restore_rt:
	mov $15, %rax
	syscall
.size __restore_rt,.-__restore_rt
