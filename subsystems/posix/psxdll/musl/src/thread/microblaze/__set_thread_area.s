.set ___set_thread_area, __set_thread_area
.global ___set_thread_area
__set_thread_area:
	ori      r21, r5, 0
	rtsd     r15, 8
	ori      r3, r0, 0
