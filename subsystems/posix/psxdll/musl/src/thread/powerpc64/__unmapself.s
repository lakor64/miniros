	.text
	.set ___unmapself, __unmapself
.global ___unmapself
	__unmapself:
	li      0, 91 # __NR_munmap
	sc
	li      0, 1 #__NR_exit
	sc
	blr
