.set _log10f, log10f
.global _log10f
log10f:
	fldlg2
	flds 4(%esp)
	fyl2x
	fstps 4(%esp)
	flds 4(%esp)
	ret
