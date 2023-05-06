.set _llrintl, llrintl
.global _llrintl
llrintl:
	fldt 8(%esp)
	fistpll 8(%esp)
	mov 8(%esp),%rax
	ret
