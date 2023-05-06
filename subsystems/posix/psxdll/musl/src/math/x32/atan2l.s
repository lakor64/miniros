.set _atan2l, atan2l
.global _atan2l
atan2l:
	fldt 8(%esp)
	fldt 24(%esp)
	fpatan
	ret
