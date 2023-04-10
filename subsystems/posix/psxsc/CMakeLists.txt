spec2def(psxsc.dll psxsc.spec ADD_IMPORTLIB)

list(APPEND PCH_SKIP_SOURCE
    ${CMAKE_CURRENT_BINARY_DIR}/psxsc_stubs.c)

add_asm_files(psxsc_asm syscall.S)

add_library(psxsc SHARED 
    psxsc.rc
    ${psxsc_asm}
    ${CMAKE_CURRENT_BINARY_DIR}/psxsc.def
    ${PCH_SKIP_SOURCE}
)
add_importlibs(psxsc ntdll)
set_module_type(psxsc posix ENTRYPOINT 0)

add_pch(psxsc stdafx.h "${PCH_SKIP_SOURCE}")
add_dependencies(psxsc asm)
target_include_directories(psxsc PRIVATE ${CMAKE_SOURCE_DIR}/subsystems/posix/include)
add_cd_file(TARGET psxsc DESTINATION reactos/system32 NO_CAB FOR all)
