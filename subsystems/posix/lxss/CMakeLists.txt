set(SOURCE
    pch.h
    lock.c
    main.c
    lnx32k.h
    lnx32k.c
)

add_library(lxss MODULE ${SOURCE} lxss.rc)
set_module_type(lxss kernelmodedriver)
target_link_libraries(lxss ${PSEH_LIB})

add_importlibs(lxss ntoskrnl hal lxcore)
add_pch(lxss pch.h SOURCE)
add_cd_file(TARGET lxss DESTINATION reactos/system32/drivers FOR all)
