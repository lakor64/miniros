include_directories(include)

add_subdirectory(lxcore)
add_subdirectory(lxss)
add_subdirectory(psxdll)
add_subdirectory(psxss)

function(add_musl)
    include_directories(BEFORE ${CMAKE_CURRENT_LIST_DIR}/psxdll/musl/include ${CMAKE_BINARY_DIR}/musl)
endfunction()

add_subdirectory(simple) # SYSCALL TESTER
