.set _log2l, log2l
.global _log2l
log2l:
	fld1
	fldt 8(%rsp)
	fyl2x
	ret
