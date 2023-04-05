spec2def(lxcore.sys lxcore.spec ADD_IMPORTLIB)

set(SYSCALLS_SRC
    file.c
)

list(TRANSFORM SYSCALLS_SRC PREPEND "syscalls/")
source_group("syscalls" FILES ${SYSCALLS_SRC})

set(SOURCE
    pch.h
    lock.h
    lock.c
    main.c
    syscall.c
    syscall.h
    ${SYSCALLS_SRC}
)

add_library(lxcore MODULE ${SOURCE} lxcore.rc ${CMAKE_CURRENT_BINARY_DIR}/lxcore.def)
set_module_type(lxcore kernelmodedriver)
target_link_directories(lxcore PRIVATE ${PSEH_LIB})

add_importlibs(lxcore ntoskrnl hal)
add_pch(lxcore pch.h SOURCE)
add_cd_file(TARGET lxcore DESTINATION reactos/system32/drivers FOR all)
