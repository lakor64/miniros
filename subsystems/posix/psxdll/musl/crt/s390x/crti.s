.section .init
.align 2
.set __init, _init
.global __init
_init:
	stmg %r14, %r15, 112(%r15)
	lgr  %r0,  %r15
	aghi %r15, -160
	stg  %r0,  0(%r15)

.section .fini
.align 2
.set __fini, _fini
.global __fini
_fini:
	stmg %r14, %r15, 112(%r15)
	lgr  %r0,  %r15
	aghi %r15, -160
	stg  %r0,  0(%r15)
