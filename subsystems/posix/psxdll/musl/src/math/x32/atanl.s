.set _atanl, atanl
.global _atanl
atanl:
	fldt 8(%esp)
	fld1
	fpatan
	ret
