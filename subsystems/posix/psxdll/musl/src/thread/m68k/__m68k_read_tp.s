.text
.set ___m68k_read_tp, __m68k_read_tp
.global ___m68k_read_tp
__m68k_read_tp:
	move.l #333,%d0
	trap #0
	move.l %d0,%a0
	rts
