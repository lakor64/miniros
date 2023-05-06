.text
.set _dlsym, dlsym
.global _dlsym
dlsym:
	push (%esp)
	push 12(%esp)
	push 12(%esp)
	call ___dlsym
	add $12,%esp
	ret
