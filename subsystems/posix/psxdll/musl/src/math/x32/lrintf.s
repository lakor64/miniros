.set _lrintf, lrintf
.global _lrintf
lrintf:
	cvtss2si %xmm0,%rax
	ret
