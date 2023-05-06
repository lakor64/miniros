.section .init
.align 2
.set __init, _init
.global __init
_init:
	stwu 1,-32(1)
	mflr 0
	stw 0,36(1)

.section .fini
.align 2
.set __fini, _fini
.global __fini
_fini:
	stwu 1,-32(1)
	mflr 0
	stw 0,36(1)
