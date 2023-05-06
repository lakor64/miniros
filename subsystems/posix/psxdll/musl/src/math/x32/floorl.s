.set _floorl, floorl
.global _floorl
floorl:
	fldt 8(%esp)
1:	mov $0x7,%al
1:	fstcw 8(%esp)
	mov 9(%esp),%ah
	mov %al,9(%esp)
	fldcw 8(%esp)
	frndint
	mov %ah,9(%esp)
	fldcw 8(%esp)
	ret

.set _ceill, ceill
.global _ceill
ceill:
	fldt 8(%esp)
	mov $0xb,%al
	jmp 1b

.set _truncl, truncl
.global _truncl
truncl:
	fldt 8(%esp)
	mov $0xf,%al
	jmp 1b
