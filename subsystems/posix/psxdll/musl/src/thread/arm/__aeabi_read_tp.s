.syntax unified
.set ___aeabi_read_tp, __aeabi_read_tp
.global ___aeabi_read_tp
__aeabi_read_tp:
	ldr r0,1f
	add r0,r0,pc
	ldr r0,[r0]
2:	bx r0
	.align 2
1:	.word __a_gettp_ptr - 2b
