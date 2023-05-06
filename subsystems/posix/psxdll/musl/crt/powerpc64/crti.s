.section .init
.align 2
.set __init, _init
.global __init
_init:
	addis 2, 12, .TOC.-_init@ha
	addi  2,  2, .TOC.-_init@l
	.localentry _init,.-_init
	mflr 0
	std  0, 16(1)
	stdu 1,-32(1)

.section .fini
.align 2
.set __fini, _fini
.global __fini
_fini:
	addis 2, 12, .TOC.-_fini@ha
	addi  2,  2, .TOC.-_fini@l
	.localentry _fini,.-_fini
	mflr 0
	std  0, 16(1)
	stdu 1,-32(1)
