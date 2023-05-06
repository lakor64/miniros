.set ___restore, __restore
.global ___restore
__restore:
	popl %eax
	movl $119, %eax
	int $0x80

.set ___restore_rt, __restore_rt
.global ___restore_rt
__restore_rt:
	movl $173, %eax
	int $0x80
