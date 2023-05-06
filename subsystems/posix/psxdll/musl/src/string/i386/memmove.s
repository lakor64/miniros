.set _memmove, memmove
.global _memmove
memmove:
	mov 4(%esp),%eax
	sub 8(%esp),%eax
	cmp 12(%esp),%eax
	jae ___memcpy_fwd
	push %esi
	push %edi
	mov 12(%esp),%edi
	mov 16(%esp),%esi
	mov 20(%esp),%ecx
	lea -1(%edi,%ecx),%edi
	lea -1(%esi,%ecx),%esi
	std
	rep movsb
	cld
	lea 1(%edi),%eax
	pop %edi
	pop %esi
	ret
