.set _sqrtf, sqrtf
.global _sqrtf
sqrtf:  sqrtss %xmm0, %xmm0
	ret
