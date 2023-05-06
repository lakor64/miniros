.text
.set ___set_thread_area, __set_thread_area
.global ___set_thread_area
__set_thread_area:
	# mov pointer in reg3 into r2
	mr 2, 3
	# put 0 into return reg
	li 3, 0
	# return
	blr

