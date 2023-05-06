.set _sqrt, sqrt
.global _sqrt
sqrt:	sqrtsd %xmm0, %xmm0
	ret
