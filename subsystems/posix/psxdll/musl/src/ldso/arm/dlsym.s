.syntax unified
.text
.set _dlsym, dlsym
.global _dlsym
dlsym:
	mov r2,lr
	b __dlsym
