spec2def(lxcore.sys lxcore.spec ADD_IMPORTLIB)
include_directories(.)

set(SYSCALLS_SRC
    file.c
    stub.c
)

list(TRANSFORM SYSCALLS_SRC PREPEND "syscalls/")
source_group("syscalls" FILES ${SYSCALLS_SRC})

set(SOURCE
    pch.h
    main.c
    syscall.h
    pico.c
    ss.c
    utls.h
    utls.c
    ${SYSCALLS_SRC}
)

add_library(lxcore MODULE ${SOURCE} lxcore.rc ${CMAKE_CURRENT_BINARY_DIR}/lxcore.def)
target_link_libraries(lxcore ${PSEH_LIB})

set_module_type(lxcore kernelmodedriver)

add_importlibs(lxcore ntoskrnl hal)
add_pch(lxcore pch.h SOURCE)
add_cd_file(TARGET lxcore DESTINATION reactos/system32/drivers FOR all)
