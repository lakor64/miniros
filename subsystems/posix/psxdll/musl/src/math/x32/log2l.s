.set _log2l, log2l
.global _log2l
log2l:
	fld1
	fldt 8(%esp)
	fyl2x
	ret
