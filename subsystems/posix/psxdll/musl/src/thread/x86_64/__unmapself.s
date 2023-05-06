/* Copyright 2011-2012 Nicholas J. Kain, licensed under standard MIT license */
.text
.set ___unmapself, __unmapself
.global ___unmapself
__unmapself:
	movl $11,%eax   /* SYS_munmap */
	syscall         /* munmap(arg2,arg3) */
	xor %rdi,%rdi   /* exit() args: always return success */
	movl $60,%eax   /* SYS_exit */
	syscall         /* exit(0) */
