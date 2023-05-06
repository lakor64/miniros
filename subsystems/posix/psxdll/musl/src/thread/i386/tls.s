.text
.set ____tls_get_addr, ___tls_get_addr
.global ____tls_get_addr
___tls_get_addr:
	mov %gs:4,%edx
	mov (%eax),%ecx
	mov 4(%eax),%eax
	add (%edx,%ecx,4),%eax
	ret
