.set _remquof, remquof
.global _remquof
remquof:
	mov 12(%esp),%ecx
	flds 8(%esp)
	flds 4(%esp)
	mov 11(%esp),%dh
	xor 7(%esp),%dh
	jmp 1f

.set _remquol, remquol
.global _remquol
remquol:
	mov 28(%esp),%ecx
	fldt 16(%esp)
	fldt 4(%esp)
	mov 25(%esp),%dh
	xor 13(%esp),%dh
	jmp 1f

.set _remquo, remquo
.global _remquo
remquo:
	mov 20(%esp),%ecx
	fldl 12(%esp)
	fldl 4(%esp)
	mov 19(%esp),%dh
	xor 11(%esp),%dh
1:	fprem1
	fnstsw %ax
	sahf
	jp 1b
	fstp %st(1)
	mov %ah,%dl
	shr %dl
	and $1,%dl
	mov %ah,%al
	shr $5,%al
	and $2,%al
	or %al,%dl
	mov %ah,%al
	shl $2,%al
	and $4,%al
	or %al,%dl
	test %dh,%dh
	jns 1f
	neg %dl
1:	movsbl %dl,%edx
	mov %edx,(%ecx)
	ret
