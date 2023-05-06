.set _floorf, floorf
.global _floorf
floorf:
	flds 4(%esp)
	jmp 1f

.set _floorl, floorl
.global _floorl
floorl:
	fldt 4(%esp)
	jmp 1f

.set _floor, floor
.global _floor
floor:
	fldl 4(%esp)
1:	mov $0x7,%al
1:	fstcw 4(%esp)
	mov 5(%esp),%ah
	mov %al,5(%esp)
	fldcw 4(%esp)
	frndint
	mov %ah,5(%esp)
	fldcw 4(%esp)
	ret

.set _ceil, ceil
.global _ceil
ceil:
	fldl 4(%esp)
	mov $0xb,%al
	jmp 1b

.set _ceilf, ceilf
.global _ceilf
ceilf:
	flds 4(%esp)
	mov $0xb,%al
	jmp 1b

.set _ceill, ceill
.global _ceill
ceill:
	fldt 4(%esp)
	mov $0xb,%al
	jmp 1b

.set _trunc, trunc
.global _trunc
trunc:
	fldl 4(%esp)
	mov $0xf,%al
	jmp 1b

.set _truncf, truncf
.global _truncf
truncf:
	flds 4(%esp)
	mov $0xf,%al
	jmp 1b

.set _truncl, truncl
.global _truncl
truncl:
	fldt 4(%esp)
	mov $0xf,%al
	jmp 1b
