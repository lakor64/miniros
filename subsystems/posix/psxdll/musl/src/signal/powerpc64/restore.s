	.set ___restore, __restore
.global ___restore
		__restore:
	li      0, 119 #__NR_sigreturn
	sc

	.set ___restore_rt, __restore_rt
.global ___restore_rt
		__restore_rt:
	li      0, 172 # __NR_rt_sigreturn
	sc
