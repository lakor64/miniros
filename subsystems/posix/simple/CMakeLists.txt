add_musl()

add_executable(simple simple.c)
add_cd_file(TARGET simple DESTINATION reactos/sbin FOR all)
set_module_type(simple posix)
add_importlibs(simple psxdll ntdll)
#target_link_libraries(simple psxdll)
