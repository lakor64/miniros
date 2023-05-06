.text
.set ___unmapself, __unmapself
.global ___unmapself
__unmapself:
	svc 91 # SYS_munmap
	svc 1  # SYS_exit
