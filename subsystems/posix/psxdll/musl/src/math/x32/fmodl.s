.set _fmodl, fmodl
.global _fmodl
fmodl:
	fldt 24(%esp)
	fldt 8(%esp)
1:	fprem
	fnstsw %ax
	testb $4,%ah
	jnz 1b
	fstp %st(1)
	ret
