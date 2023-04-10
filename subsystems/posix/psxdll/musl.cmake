
set(STDLIB_SRC abs.c
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
wcstol.c)

list(TRANSFORM STDLIB_SRC PREPEND musl/src/stdlib/)

# Static dep of musl
add_library(musl STATIC ${STDLIB_SRC})

#rm_ros_inc(musl) # TODO new...

target_include_directories(musl PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/musl/include 

    # TODO: THIS HAS TO BE MODIFIED FOR OTHER PLATFORMS
    ${CMAKE_CURRENT_LIST_DIR}/musl/arch/i386

    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/musl/src/internal
	${CMAKE_CURRENT_LIST_DIR}/musl/include
)
