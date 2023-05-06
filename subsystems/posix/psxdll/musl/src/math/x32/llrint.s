.set _llrint, llrint
.global _llrint
llrint:
	cvtsd2si %xmm0,%rax
	ret
