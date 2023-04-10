include_directories(
    ${REACTOS_SOURCE_DIR}/sdk/include/reactos/subsys)

add_executable(psxss api.c psxss.c psxss.rc)
set_module_type(psxss nativecui)
target_link_libraries(psxss nt smlib)
add_importlibs(psxss ntdll)
add_dependencies(psxss psdk)
add_cd_file(TARGET psxss DESTINATION reactos/system32 FOR all)
