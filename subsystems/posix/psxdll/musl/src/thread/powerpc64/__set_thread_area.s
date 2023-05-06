.text
.set ___set_thread_area, __set_thread_area
.global ___set_thread_area
__set_thread_area:
	mr 13, 3
	li  3, 0
	blr

