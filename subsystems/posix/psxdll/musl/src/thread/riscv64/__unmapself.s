.set ___unmapself, __unmapself
.global ___unmapself
__unmapself:
	li a7, 215 # SYS_munmap
	ecall
	li a7, 93  # SYS_exit
	ecall
