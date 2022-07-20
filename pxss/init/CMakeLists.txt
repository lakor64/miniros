
include_directories(${REACTOS_SOURCE_DIR}/sdk/include/reactos/subsys)

list(APPEND SOURCE
    init.c
    pch.h)

add_executable(smss WIN32 ${SOURCE})
target_link_libraries(smss nt ${PSEH_LIB})
set_module_type(smss nativecui)
add_importlibs(smss ntdll)
add_pch(smss pch.h SOURCE)
add_cd_file(TARGET smss DESTINATION reactos/system32 FOR all)
