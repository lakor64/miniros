__asm__(
".text\n"
".weak _DYNAMIC \n"
".global " START "\n"
START ":\n"
"	xor %ebp,%ebp \n"
"	mov %esp,%eax \n"
"	and $-16,%esp \n"
"	push %eax \n"
"	push %eax \n"
"	call 1f \n"
"1:	addl $_DYNAMIC-1b,(%esp) \n"
"	push %eax \n"
"	call " START "_c \n"
);
