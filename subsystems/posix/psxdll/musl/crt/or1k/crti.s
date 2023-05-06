.section .init
.set __init, _init
.global __init
_init:
	l.addi	r1,r1,-4
	l.sw	0(r1),r9

.section .fini
.set __fini, _fini
.global __fini
_fini:
	l.addi  r1,r1,-4
	l.sw    0(r1),r9
