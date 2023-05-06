.set _rintl, rintl
.global _rintl
rintl:
	fldt 8(%esp)
	frndint
	ret
