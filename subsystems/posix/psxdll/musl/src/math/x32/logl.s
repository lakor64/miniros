.set _logl, logl
.global _logl
logl:
	fldln2
	fldt 8(%esp)
	fyl2x
	ret
