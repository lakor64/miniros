	.text
	.set _dlsym, dlsym
.global _dlsym
		dlsym:
	mflr    5                      # The return address is arg3.
	b       __dlsym
	.size   dlsym, .-dlsym
