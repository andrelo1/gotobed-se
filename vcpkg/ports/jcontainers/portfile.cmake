vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO ryobg/JContainers
    REF 3cd24b1053b334fed3feb51d80fc1ea495711eff
    SHA512 c618c6f9189d5f3bb78ceb12dd81aaf0f96cf910309777bfeb678bb8ea0240194143910abd3a069848023f3e9350bc110606a797918e406c58763bafb2eea6a9
    HEAD_REF master
)

file(INSTALL "${SOURCE_PATH}/src/JContainers/src/jc_interface.h" DESTINATION "${CURRENT_PACKAGES_DIR}/include/jcontainers/")
file(INSTALL "${SOURCE_PATH}/src/JContainers/src/jcontainers_constants.h" DESTINATION "${CURRENT_PACKAGES_DIR}/include/jcontainers/")
file(INSTALL "${SOURCE_PATH}/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}" RENAME copyright)
