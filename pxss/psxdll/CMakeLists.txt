
include_directories(${CMAKE_CURRENT_LIST_DIR}/musl/include)

set(MUSL_STDLIB
    abs.c
    atof.c
    atoi.c
    atol.c
    atoll.c
    bsearch.c
    div.c
    ecvt.c
    fcvt.c
    gcvt.c
    imaxabs.c
    imaxdiv.c
    labs.c
    ldiv.c
    llabs.c
    lldiv.c
    qsort.c
    qsort_nr.c
    strtod.c
    strtol.c
    wcstod.c
    wcstol.c
)

list(TRANSFORM MUSL_STDLIB PREPEND musl/src/stdlib/)

add_library(psxdll STATIC ${MUSL_STDLIB})
add_importlibs(psxdll ntdll)
add_cd_file(TARGET psxdll DESTINATION reactos/lib FOR all)

