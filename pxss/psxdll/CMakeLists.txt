add_library(psxdll STATIC 
    syscalls.c
)
add_importlibs(psxdll ntdll)
add_cd_file(TARGET psxdll DESTINATION reactos/lib FOR all)
set_subsystem(psxdll console)
set_module_type(psxdll win32dll ENTRYPOINT 0)

target_include_directories(psxdll PRIVATE ${CMAKE_SOURCE_DIR}/pxss/include/nt)
