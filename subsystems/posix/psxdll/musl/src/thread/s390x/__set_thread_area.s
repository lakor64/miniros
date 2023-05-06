.text
.set ___set_thread_area, __set_thread_area
.global ___set_thread_area
__set_thread_area:
	sar  %a1, %r2
	srlg %r2, %r2, 32
	sar  %a0, %r2
	lghi %r2, 0
	br   %r14
