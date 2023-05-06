.text
.set ___tlsdesc_static, __tlsdesc_static
.global ___tlsdesc_static
__tlsdesc_static:
	mov 4(%eax),%eax
	ret

.set ___tlsdesc_dynamic, __tlsdesc_dynamic
.global ___tlsdesc_dynamic
__tlsdesc_dynamic:
	mov 4(%eax),%eax
	push %edx
	mov %gs:4,%edx
	push %ecx
	mov (%eax),%ecx
	mov 4(%eax),%eax
	add (%edx,%ecx,4),%eax
	pop %ecx
	sub %gs:0,%eax
	pop %edx
	ret
