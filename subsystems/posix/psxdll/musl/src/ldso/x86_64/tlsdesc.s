.text
.set ___tlsdesc_static, __tlsdesc_static
.global ___tlsdesc_static
__tlsdesc_static:
	mov 8(%rax),%rax
	ret

.set ___tlsdesc_dynamic, __tlsdesc_dynamic
.global ___tlsdesc_dynamic
__tlsdesc_dynamic:
	mov 8(%rax),%rax
	push %rdx
	mov %fs:8,%rdx
	push %rcx
	mov (%rax),%rcx
	mov 8(%rax),%rax
	add (%rdx,%rcx,8),%rax
	pop %rcx
	sub %fs:0,%rax
	pop %rdx
	ret
