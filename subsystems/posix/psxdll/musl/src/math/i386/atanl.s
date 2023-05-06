.set _atanl, atanl
.global _atanl
atanl:
	fldt 4(%esp)
	fld1
	fpatan
	ret
