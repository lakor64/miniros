.set _dlsym, dlsym
.global _dlsym
dlsym:
	mv a2, ra
	tail __dlsym
