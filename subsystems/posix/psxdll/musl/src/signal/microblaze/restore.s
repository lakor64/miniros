.set ___restore, __restore
.global ___restore
__restore:
	ori     r12, r0, 119
	brki    r14, 0x8

.set ___restore_rt, __restore_rt
.global ___restore_rt
__restore_rt:
	ori     r12, r0, 173
	brki    r14, 0x8
