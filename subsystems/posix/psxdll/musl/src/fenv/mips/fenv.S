#ifndef __mips_soft_float

.set noreorder

.set _feclearexcept, feclearexcept
.global _feclearexcept
feclearexcept:
	and     $4, $4, 0x7c
	cfc1    $5, $31
	or      $5, $5, $4
	xor     $5, $5, $4
	ctc1    $5, $31
	jr      $ra
	li      $2, 0

.set _feraiseexcept, feraiseexcept
.global _feraiseexcept
feraiseexcept:
	and     $4, $4, 0x7c
	cfc1    $5, $31
	or      $5, $5, $4
	ctc1    $5, $31
	jr      $ra
	li      $2, 0

.set _fetestexcept, fetestexcept
.global _fetestexcept
fetestexcept:
	and     $4, $4, 0x7c
	cfc1    $2, $31
	jr      $ra
	and     $2, $2, $4

.set _fegetround, fegetround
.global _fegetround
fegetround:
	cfc1    $2, $31
	jr      $ra
	andi    $2, $2, 3

.set ___fesetround, __fesetround
.global ___fesetround
__fesetround:
	cfc1    $5, $31
	li      $6, -4
	and     $5, $5, $6
	or      $5, $5, $4
	ctc1    $5, $31
	jr      $ra
	li      $2, 0

.set _fegetenv, fegetenv
.global _fegetenv
fegetenv:
	cfc1    $5, $31
	sw      $5, 0($4)
	jr      $ra
	li      $2, 0

.set _fesetenv, fesetenv
.global _fesetenv
fesetenv:
	addiu   $5, $4, 1
	beq     $5, $0, 1f
	 nop
	lw      $5, 0($4)
1:	ctc1    $5, $31
	jr      $ra
	li      $2, 0

#endif
