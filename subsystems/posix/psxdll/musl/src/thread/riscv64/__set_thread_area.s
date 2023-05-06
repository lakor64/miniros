.set ___set_thread_area, __set_thread_area
.global ___set_thread_area
__set_thread_area:
	mv tp, a0
	li a0, 0
	ret
