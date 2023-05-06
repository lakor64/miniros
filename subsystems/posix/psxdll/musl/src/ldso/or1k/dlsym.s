.set _dlsym, dlsym
.global _dlsym
dlsym:
	l.j	__dlsym
	 l.ori	r5, r9, 0
