.section .init
.set _ _init,  _init
.global _ _init
_init:
	add #-4, r15
	mov.l r12, @-r15
	mov.l r14, @-r15
	sts.l pr, @-r15
	mov r15, r14
	nop

.section .fini
.set _ _fini,  _fini
.global _ _fini
_fini:
	add #-4, r15
	mov.l r12, @-r15
	mov.l r14, @-r15
	sts.l pr, @-r15
	mov r15, r14
	nop
