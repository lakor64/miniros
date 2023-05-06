.set noreorder

.section .init
.set __init, _init
.global __init
.align 2
_init:
	subu $sp,$sp,32
	sw $gp,24($sp)
	sw $ra,28($sp)

.section .fini
.set __fini, _fini
.global __fini
.align 2
_fini:
	subu $sp,$sp,32
	sw $gp,24($sp)
	sw $ra,28($sp)
