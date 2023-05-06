.syntax unified

.section .init
.set __init, _init
.global __init
_init:
	push {r0,lr}

.section .fini
.set __fini, _fini
.global __fini
_fini:
	push {r0,lr}
