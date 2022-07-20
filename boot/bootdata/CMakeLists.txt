
add_subdirectory(packages)

# Common hives

#add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/txtsetup.sif DESTINATION reactos NO_CAB FOR bootcd regtest)

add_custom_target(converted_caroots_inf DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/caroots.inf)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/caroots.inf
                   COMMAND native-utf16le "${CMAKE_CURRENT_SOURCE_DIR}/caroots.inf" "${CMAKE_CURRENT_BINARY_DIR}/caroots.inf"
                   DEPENDS native-utf16le ${CMAKE_CURRENT_SOURCE_DIR}/caroots.inf)
add_cd_file(TARGET converted_caroots_inf FILE ${CMAKE_CURRENT_BINARY_DIR}/caroots.inf DESTINATION reactos NO_CAB FOR bootcd regtest)

add_registry_inf(
    hivesys.inf
    hivebcd.inf)

# autorun.inf
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/autorun-livecd.inf DESTINATION root NO_CAB NOT_IN_HYBRIDCD NAME_ON_CD autorun.inf FOR livecd)

# icon.ico
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/icon.ico DESTINATION root NO_CAB NOT_IN_HYBRIDCD FOR all hybridcd)

# readme.txt
#add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/readme.txt DESTINATION reactos FOR all)

# freeldr.ini
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/livecd.ini DESTINATION root NOT_IN_HYBRIDCD NAME_ON_CD freeldr.ini FOR livecd)

# Unattend
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/bootcdregtest/unattend.inf DESTINATION reactos NO_CAB FOR regtest)
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/bootcd/unattend.inf DESTINATION reactos NO_CAB FOR bootcd)
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/livecd/unattend.inf DESTINATION reactos NO_CAB FOR livecd)
