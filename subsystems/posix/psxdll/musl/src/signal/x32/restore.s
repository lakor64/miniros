	nop
.set ___restore_rt, __restore_rt
.global ___restore_rt
__restore_rt:
	mov $0x40000201, %rax /* SYS_rt_sigreturn */
	syscall
.size __restore_rt,.-__restore_rt
