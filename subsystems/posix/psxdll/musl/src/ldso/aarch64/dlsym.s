.set _dlsym, dlsym
.global _dlsym
dlsym:
	mov x2,x30
	b __dlsym
