
include_directories(${REACTOS_SOURCE_DIR}/sdk/include/reactos/subsys)

list(APPEND SOURCE
    main.c
    pch.h)

add_executable(psxss WIN32 ${SOURCE})
target_link_libraries(psxss nt ${PSEH_LIB})
set_module_type(psxss nativecui)
add_importlibs(psxss ntdll)
add_pch(psxss pch.h SOURCE)
add_cd_file(TARGET psxss DESTINATION reactos/sbin FOR all)
