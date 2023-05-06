.set _llrintf, llrintf
.global _llrintf
llrintf:
	cvtss2si %xmm0,%rax
	ret
