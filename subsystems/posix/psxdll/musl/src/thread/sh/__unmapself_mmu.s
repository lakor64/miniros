.text
.set ___unmapself_sh_mmu, __unmapself_sh_mmu
.global ___unmapself_sh_mmu
__unmapself_sh_mmu:
	mov   #91, r3  ! SYS_munmap
	trapa #31

	or    r0, r0
	or    r0, r0
	or    r0, r0
	or    r0, r0
	or    r0, r0

	mov   #1, r3   ! SYS_exit
	mov   #0, r4
	trapa #31

	or    r0, r0
	or    r0, r0
	or    r0, r0
	or    r0, r0
	or    r0, r0
