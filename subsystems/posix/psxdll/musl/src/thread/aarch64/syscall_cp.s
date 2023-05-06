// __syscall_cp_asm(&self->cancel, nr, u, v, w, x, y, z)
//                  x0             x1  x2 x3 x4 x5 x6 x7

// syscall(nr, u, v, w, x, y, z)
//         x8  x0 x1 x2 x3 x4 x5

.set ___cp_begin, __cp_begin
.global ___cp_begin
.set ___cp_end, __cp_end
.global ___cp_end
.set ___cp_cancel, __cp_cancel
.global ___cp_cancel
.set ___syscall_cp_asm, __syscall_cp_asm
.global ___syscall_cp_asm
__syscall_cp_asm:
__cp_begin:
	ldr w0,[x0]
	cbnz w0,__cp_cancel
	mov x8,x1
	mov x0,x2
	mov x1,x3
	mov x2,x4
	mov x3,x5
	mov x4,x6
	mov x5,x7
	svc 0
__cp_end:
	ret
__cp_cancel:
	b __cancel
