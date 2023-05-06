.syntax unified
.text

.set ___a_barrier_dummy, __a_barrier_dummy
.global ___a_barrier_dummy
__a_barrier_dummy:
	bx lr

.set ___a_barrier_oldkuser, __a_barrier_oldkuser
.global ___a_barrier_oldkuser
__a_barrier_oldkuser:
	push {r0,r1,r2,r3,ip,lr}
	mov r1,r0
	mov r2,sp
	ldr ip,=0xffff0fc0
	bl 1f
	pop {r0,r1,r2,r3,ip,lr}
	bx lr
1:	bx ip

.set ___a_barrier_v6, __a_barrier_v6
.global ___a_barrier_v6
__a_barrier_v6:
	.arch armv6t2
	mcr p15,0,r0,c7,c10,5
	bx lr

.set ___a_barrier_v7, __a_barrier_v7
.global ___a_barrier_v7
__a_barrier_v7:
	.arch armv7-a
	dmb ish
	bx lr

.set ___a_cas_dummy, __a_cas_dummy
.global ___a_cas_dummy
__a_cas_dummy:
	mov r3,r0
	ldr r0,[r2]
	subs r0,r3,r0
	streq r1,[r2]
	bx lr

.set ___a_cas_v6, __a_cas_v6
.global ___a_cas_v6
__a_cas_v6:
	.arch armv6t2
	mov r3,r0
	mcr p15,0,r0,c7,c10,5
1:	ldrex r0,[r2]
	subs r0,r3,r0
	strexeq r0,r1,[r2]
	teqeq r0,#1
	beq 1b
	mcr p15,0,r0,c7,c10,5
	bx lr

.set ___a_cas_v7, __a_cas_v7
.global ___a_cas_v7
__a_cas_v7:
	.arch armv7-a
	mov r3,r0
	dmb ish
1:	ldrex r0,[r2]
	subs r0,r3,r0
	strexeq r0,r1,[r2]
	teqeq r0,#1
	beq 1b
	dmb ish
	bx lr

.set ___a_gettp_cp15, __a_gettp_cp15
.global ___a_gettp_cp15
__a_gettp_cp15:
	mrc p15,0,r0,c13,c0,3
	bx lr

/* Tag this file with minimum ISA level so as not to affect linking. */
.object_arch armv4t
.eabi_attribute 6,2

.data
.align 2

.set ___a_barrier_ptr, __a_barrier_ptr
.global ___a_barrier_ptr
__a_barrier_ptr:
	.word __a_barrier_dummy

.set ___a_cas_ptr, __a_cas_ptr
.global ___a_cas_ptr
__a_cas_ptr:
	.word __a_cas_dummy

.set ___a_gettp_ptr, __a_gettp_ptr
.global ___a_gettp_ptr
__a_gettp_ptr:
	.word __a_gettp_cp15
