.set _log2f, log2f
.global _log2f
log2f:
	fld1
	flds 4(%esp)
	fyl2x
	fstps 4(%esp)
	flds 4(%esp)
	ret
