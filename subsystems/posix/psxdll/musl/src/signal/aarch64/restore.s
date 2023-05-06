.set ___restore, __restore
.global ___restore
__restore:
.set ___restore_rt, __restore_rt
.global ___restore_rt
__restore_rt:
	mov x8,#139 // SYS_rt_sigreturn
	svc 0
