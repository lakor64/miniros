.set _dlsym, dlsym
.global _dlsym
dlsym:
	brid    __dlsym
	add     r7, r15, r0
