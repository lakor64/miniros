.set noreorder

.set ___restore_rt, __restore_rt
.global ___restore_rt
__restore_rt:
	li $2, 4193
	syscall

.set ___restore, __restore
.global ___restore
__restore:
	li $2, 4119
	syscall
