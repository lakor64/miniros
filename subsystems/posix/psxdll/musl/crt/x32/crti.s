.section .init
.set __init, _init
.global __init
_init:
	push %rax

.section .fini
.set __fini, _fini
.global __fini
_fini:
	push %rax
