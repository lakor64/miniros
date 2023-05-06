.set _log10l, log10l
.global _log10l
log10l:
	fldlg2
	fldt 8(%rsp)
	fyl2x
	ret
