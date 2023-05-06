.set ___set_thread_area, __set_thread_area
.global ___set_thread_area
__set_thread_area:
	msr tpidr_el0,x0
	mov w0,#0
	ret
