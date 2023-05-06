.syntax unified

.set ___aeabi_memclr8, __aeabi_memclr8
.global ___aeabi_memclr8
.set ___aeabi_memclr4, __aeabi_memclr4
.global ___aeabi_memclr4
.set ___aeabi_memclr, __aeabi_memclr
.global ___aeabi_memclr
.set ___aeabi_memset8, __aeabi_memset8
.global ___aeabi_memset8
.set ___aeabi_memset4, __aeabi_memset4
.global ___aeabi_memset4
.set ___aeabi_memset, __aeabi_memset
.global ___aeabi_memset


__aeabi_memclr8:
__aeabi_memclr4:
__aeabi_memclr:
	movs  r2, #0
__aeabi_memset8:
__aeabi_memset4:
__aeabi_memset:
	cmp   r1, #0
	beq   2f
	adds  r1, r0, r1
1:	strb  r2, [r0]
	adds  r0, r0, #1
	cmp   r1, r0
	bne   1b
2:	bx    lr
