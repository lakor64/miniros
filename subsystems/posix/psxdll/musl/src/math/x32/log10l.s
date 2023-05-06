.set _log10l, log10l
.global _log10l
log10l:
	fldlg2
	fldt 8(%esp)
	fyl2x
	ret
