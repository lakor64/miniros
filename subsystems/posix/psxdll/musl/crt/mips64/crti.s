.set noreorder

.section .init
.set __init, _init
.global __init
.align 3
_init:
	dsubu	$sp, $sp, 32
	sd	$gp, 16($sp)
	sd	$ra, 24($sp)

.section .fini
.set __fini, _fini
.global __fini
.align 3
_fini:
	dsubu	$sp, $sp, 32
	sd	$gp, 16($sp)
	sd	$ra, 24($sp)
