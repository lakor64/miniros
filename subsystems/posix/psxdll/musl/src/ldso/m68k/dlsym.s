.text
.set _dlsym, dlsym
.global _dlsym
dlsym:
	move.l (%sp),-(%sp)
	move.l 12(%sp),-(%sp)
	move.l 12(%sp),-(%sp)
	lea __dlsym-.-8,%a1
	jsr (%pc,%a1)
	add.l #12,%sp
	rts
