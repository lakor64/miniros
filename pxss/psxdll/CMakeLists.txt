add_library(psxdll SHARED 
    syscalls.c
)
add_importlibs(psxdll ntdll)
add_cd_file(TARGET psxdll DESTINATION reactos/lib FOR all)
set_module_type(psxdll win32dll)
#############################################
## HACK FOR MSVC COMPILATION WITH win32dll ##
set_subsystem(psxdll console)
################# END  HACK #################

target_include_directories(psxdll PRIVATE ${CMAKE_SOURCE_DIR}/pxss/include/nt)
