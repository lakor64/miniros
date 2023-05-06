.set ___unmapself, __unmapself
.global ___unmapself
__unmapself:
	mov x8,#215 // SYS_munmap
	svc 0
	mov x8,#93 // SYS_exit
	svc 0
