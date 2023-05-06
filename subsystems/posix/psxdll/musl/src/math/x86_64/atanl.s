.set _atanl, atanl
.global _atanl
atanl:
	fldt 8(%rsp)
	fld1
	fpatan
	ret
