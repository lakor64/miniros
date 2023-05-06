.set _log2, log2
.global _log2
log2:
	fld1
	fldl 4(%esp)
	fyl2x
	fstpl 4(%esp)
	fldl 4(%esp)
	ret
