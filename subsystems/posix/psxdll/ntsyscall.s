#
#   musl syscall entrypoint -> nt syscall
#    i386
#

#include <asm.inc>

#define KUSER_SHARED_SYSCALL HEX(7ffe0300)

.code

MACRO(K_START, Name)
PUBLIC Name
.PROC Name
FPO 0, 0, 0, 0, 0, FRAME_FPO
mov eax, 2
shl eax, 12
add eax, [esp+4]
ENDM

MACRO(K_END, Args)
add esp, 4
mov edx, KUSER_SHARED_SYSCALL
call dword ptr [edx]
sub esp, 4
ret 4 * Args
.ENDP
ENDM

K_START ___syscall0
K_END 1

K_START ___syscall1
K_END 2

K_START ___syscall2
K_END 3

K_START ___syscall3
K_END 4

K_START ___syscall4
K_END 5

K_START ___syscall5
K_END 6

K_START ___syscall6
K_END 7
