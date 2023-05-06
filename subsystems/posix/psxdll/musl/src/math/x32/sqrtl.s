.set _sqrtl, sqrtl
.global _sqrtl
sqrtl:	fldt 8(%esp)
	fsqrt
	ret
