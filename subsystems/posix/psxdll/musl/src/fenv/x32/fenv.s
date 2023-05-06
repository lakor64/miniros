.set _feclearexcept, feclearexcept
.global _feclearexcept
feclearexcept:
		# maintain exceptions in the sse mxcsr, clear x87 exceptions
	mov %edi,%ecx
	and $0x3f,%ecx
	fnstsw %ax
	test %eax,%ecx
	jz 1f
	fnclex
1:	stmxcsr -8(%esp)
	and $0x3f,%eax
	or %eax,-8(%esp)
	test %ecx,-8(%esp)
	jz 1f
	not %ecx
	and %ecx,-8(%esp)
	ldmxcsr -8(%esp)
1:	xor %eax,%eax
	ret

.set _feraiseexcept, feraiseexcept
.global _feraiseexcept
feraiseexcept:
	and $0x3f,%edi
	stmxcsr -8(%esp)
	or %edi,-8(%esp)
	ldmxcsr -8(%esp)
	xor %eax,%eax
	ret

.set ___fesetround, __fesetround
.global ___fesetround
__fesetround:
	push %rax
	xor %eax,%eax
	mov %edi,%ecx
	fnstcw (%esp)
	andb $0xf3,1(%esp)
	or %ch,1(%esp)
	fldcw (%esp)
	stmxcsr (%esp)
	shl $3,%ch
	andb $0x9f,1(%esp)
	or %ch,1(%esp)
	ldmxcsr (%esp)
	pop %rcx
	ret

.set _fegetround, fegetround
.global _fegetround
fegetround:
	push %rax
	stmxcsr (%esp)
	pop %rax
	shr $3,%eax
	and $0xc00,%eax
	ret

.set _fegetenv, fegetenv
.global _fegetenv
fegetenv:
	xor %eax,%eax
	fnstenv (%edi)
	stmxcsr 28(%edi)
	ret

.set _fesetenv, fesetenv
.global _fesetenv
fesetenv:
	xor %eax,%eax
	inc %edi
	jz 1f
	fldenv -1(%edi)
	ldmxcsr 27(%edi)
	ret
1:	push %rax
	push %rax
	pushq $0xffff
	pushq $0x37f
	fldenv (%esp)
	pushq $0x1f80
	ldmxcsr (%esp)
	add $40,%esp
	ret

.set _fetestexcept, fetestexcept
.global _fetestexcept
fetestexcept:
	and $0x3f,%edi
	push %rax
	stmxcsr (%esp)
	pop %rsi
	fnstsw %ax
	or %esi,%eax
	and %edi,%eax
	ret
