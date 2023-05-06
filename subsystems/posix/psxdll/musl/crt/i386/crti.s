.section .init
.set __init, _init
.global __init
_init:
	sub $12,%esp

.section .fini
.set __fini, _fini
.global __fini
_fini:
	sub $12,%esp
