	.set _dlsym, dlsym
.global _dlsym
		dlsym:
	lgr %r4, %r14
	jg __dlsym
