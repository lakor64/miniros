spec2def(psxsc.dll psxsc.spec ADD_IMPORTLIB)

list(APPEND PCH_SKIP_SOURCE
    ${CMAKE_CURRENT_BINARY_DIR}/psxsc_stubs.c)

add_library(psxsc SHARED 
    file.c
    main.c
    ${CMAKE_CURRENT_BINARY_DIR}/psxsc.def
    ${PCH_SKIP_SOURCE}
)
add_importlibs(psxsc ntdll)
add_cd_file(TARGET psxsc DESTINATION reactos/sbin FOR all)
set_module_type(psxsc win32dll)
#############################################
## HACK FOR MSVC COMPILATION WITH win32dll ##
set_subsystem(psxsc console)
################# END  HACK #################

add_pch(psxsc stdafx.h "${PCH_SKIP_SOURCE}")
target_include_directories(psxsc PRIVATE ${CMAKE_SOURCE_DIR}/subsystems/posix/include)
