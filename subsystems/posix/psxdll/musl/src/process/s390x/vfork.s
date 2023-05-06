	.set _vfork, vfork
.global _vfork
	vfork:
	svc 190
		jg  __syscall_ret
