# see ../i386/acos.s

.set _acosl, acosl
.global _acosl
acosl:
	fldt 8(%esp)
1:	fld %st(0)
	fld1
	fsub %st(0),%st(1)
	fadd %st(2)
	fmulp
	fsqrt
	fabs
	fxch %st(1)
	fpatan
	ret
