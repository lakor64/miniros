/* Copyright 2011-2012 Nicholas J. Kain, licensed under standard MIT license */
.text
.set ___set_thread_area, __set_thread_area
.global ___set_thread_area
__set_thread_area:
	mov %rdi,%rsi           /* shift for syscall */
	movl $0x1002,%edi       /* SET_FS register */
	movl $158,%eax          /* set fs segment to */
	syscall                 /* arch_prctl(SET_FS, arg)*/
	ret
