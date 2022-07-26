
add_subdirectory(inf)
add_subdirectory(nls)

add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/drivers/etc/hosts DESTINATION reactos/etc FOR all)
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/drivers/etc/KDBinit DESTINATION reactos/etc FOR all)

add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/systemcompatible.manifest DESTINATION reactos/etc/manifests FOR all)
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/forwardcompatible.manifest DESTINATION reactos/etc/manifests FOR all)
