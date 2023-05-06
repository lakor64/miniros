	.set ___restore, __restore
.global ___restore
		__restore:
	svc 119 #__NR_sigreturn

	.set ___restore_rt, __restore_rt
.global ___restore_rt
		__restore_rt:
	svc 173 # __NR_rt_sigreturn
