
add_subdirectory(packages)

# Common hives

add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/txtsetup.sif DESTINATION reactos NO_CAB FOR bootcd regtest)

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
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/readme.txt DESTINATION reactos FOR all)

# Welcome.exe optional custom configuration (only for HybridCD)
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/welcome_config/)
    # Copy the main configuration file
    add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/welcome_config/welcome.ini DESTINATION bootcd/reactos NO_CAB FOR hybridcd)

    # Convert the translation files (name format: xx-YY.ini) into UTF-16
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/welcome_config)
    file(GLOB I18N_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/welcome_config/ ${CMAKE_CURRENT_SOURCE_DIR}/welcome_config/*-*.ini)
    foreach(_file ${I18N_FILES})
        set(_converted_file ${CMAKE_CURRENT_BINARY_DIR}/welcome_config/${_file})
        set(_source_file ${CMAKE_CURRENT_SOURCE_DIR}/welcome_config/${_file})
        add_custom_command(OUTPUT "${_converted_file}"
                           COMMAND native-utf16le "${_source_file}" "${_converted_file}"
                           DEPENDS native-utf16le "${_source_file}")
        add_cd_file(TARGET converted_welcome_i18n_files FILE ${_converted_file} DESTINATION bootcd/reactos/welcome NO_CAB NAME_ON_CD ${_file} FOR hybridcd)
        list(APPEND _converted_welcome_i18n_files ${_converted_file})
    endforeach(_file)
    add_custom_target(converted_welcome_i18n_files DEPENDS ${_converted_welcome_i18n_files})
endif()

# freeldr.ini
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/livecd.ini DESTINATION root NOT_IN_HYBRIDCD NAME_ON_CD freeldr.ini FOR livecd)

# Unattend
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/bootcdregtest/unattend.inf DESTINATION reactos/etc/inf NO_CAB FOR regtest)
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/bootcd/unattend.inf DESTINATION reactos/etc/inf NO_CAB FOR bootcd)
add_cd_file(FILE ${CMAKE_CURRENT_SOURCE_DIR}/livecd/unattend.inf DESTINATION reactos/etc/inf NO_CAB FOR livecd)
