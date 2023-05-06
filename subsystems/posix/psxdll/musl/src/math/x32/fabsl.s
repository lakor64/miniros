.set _fabsl, fabsl
.global _fabsl
fabsl:
	fldt 8(%esp)
	fabs
	ret
