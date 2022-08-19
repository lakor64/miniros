spec2def(psxdll.dll psxdll.spec ADD_IMPORTLIB)

add_library(psxdll SHARED 
    syscalls.c
    ${CMAKE_CURRENT_BINARY_DIR}/psxdll.def
    ${CMAKE_CURRENT_BINARY_DIR}/psxdll_stubs.c # skippch
)
add_importlibs(psxdll ntdll)
add_cd_file(TARGET psxdll DESTINATION reactos/lib FOR all)
set_module_type(psxdll win32dll ENTRYPOINT 0)
#############################################
## HACK FOR MSVC COMPILATION WITH win32dll ##
set_subsystem(psxdll console)
################# END  HACK #################

target_include_directories(psxdll PRIVATE ${CMAKE_SOURCE_DIR}/psxss/include/nt)
