.set _log10, log10
.global _log10
log10:
	fldlg2
	fldl 4(%esp)
	fyl2x
	fstpl 4(%esp)
	fldl 4(%esp)
	ret
