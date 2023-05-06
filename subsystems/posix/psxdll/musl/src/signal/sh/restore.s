.set ___restore, __restore
.global ___restore
__restore:
	mov   #119, r3  !__NR_sigreturn
	trapa #31

	or    r0, r0
	or    r0, r0
	or    r0, r0
	or    r0, r0
	or    r0, r0

.set ___restore_rt, __restore_rt
.global ___restore_rt
__restore_rt:
	mov   #100, r3  !__NR_rt_sigreturn
	add   #73, r3
	trapa #31

	or    r0, r0
	or    r0, r0
	or    r0, r0
	or    r0, r0
	or    r0, r0
