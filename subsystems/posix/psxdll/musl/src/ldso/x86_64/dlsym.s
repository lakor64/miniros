.text
.set _dlsym, dlsym
.global _dlsym
dlsym:
	mov (%rsp),%rdx
	jmp __dlsym
