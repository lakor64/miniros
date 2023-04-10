spec2def(psxdll.dll psxdll.spec ADD_IMPORTLIB)

list(APPEND PCH_SKIP_SOURCE
    ${CMAKE_CURRENT_BINARY_DIR}/psxdll_stubs.c)

# TODO: To remove and use musl one
add_asm_files(psxdll_asm syscall.S)

add_library(psxdll SHARED 
    fake.c
    psxdll.rc
    ${psxdll_asm}
    ${CMAKE_CURRENT_BINARY_DIR}/psxdll.def
    ${PCH_SKIP_SOURCE}
)
add_importlibs(psxdll ntdll)
set_module_type(psxdll posix ENTRYPOINT 0)

#add_pch(psxdll stdafx.h "${PCH_SKIP_SOURCE}")
add_dependencies(psxdll asm)
target_include_directories(psxdll PRIVATE ${CMAKE_SOURCE_DIR}/subsystems/posix/include)
add_cd_file(TARGET psxdll DESTINATION reactos/system32 NO_CAB FOR all)
