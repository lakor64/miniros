.section .init
.set __init, _init
.global __init
_init:
	stp x29,x30,[sp,-16]!
	mov x29,sp

.section .fini
.set __fini, _fini
.global __fini
_fini:
	stp x29,x30,[sp,-16]!
	mov x29,sp
