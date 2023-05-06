1:	int $128
	ret

.data
.align 4
.set ___sysinfo, __sysinfo
.global ___sysinfo
__sysinfo:
	.long 1b
