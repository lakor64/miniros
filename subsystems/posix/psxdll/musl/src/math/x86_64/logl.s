.set _logl, logl
.global _logl
logl:
	fldln2
	fldt 8(%rsp)
	fyl2x
	ret
