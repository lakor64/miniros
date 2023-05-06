.set _lrint, lrint
.global _lrint
lrint:
	cvtsd2si %xmm0,%rax
	ret
