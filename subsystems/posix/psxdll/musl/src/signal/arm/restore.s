.syntax unified

.set ___restore, __restore
.global ___restore
__restore:
	mov r7,#119
	swi 0x0

.set ___restore_rt, __restore_rt
.global ___restore_rt
__restore_rt:
	mov r7,#173
	swi 0x0
