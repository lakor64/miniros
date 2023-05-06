.section .init
.set __init, _init
.global __init
.align 2
_init:
	addi r1, r1, -32
	swi r15, r1, 0

.section .fini
.set __fini, _fini
.global __fini
.align 2
_fini:
	addi r1, r1, -32
	swi r15, r1, 0
