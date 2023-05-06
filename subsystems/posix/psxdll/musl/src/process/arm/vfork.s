.syntax unified
.set _vfork, vfork
.global _vfork
vfork:
	mov ip, r7
	mov r7, 190
	svc 0
	mov r7, ip
		b __syscall_ret
