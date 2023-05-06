.syntax unified
.text
.set ___unmapself, __unmapself
.global ___unmapself
__unmapself:
	mov r7,#91
	svc 0
	mov r7,#1
	svc 0
