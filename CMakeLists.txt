cmake_minimum_required(VERSION 3.20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

project(gotobed VERSION 2.1.0.0)

find_package(CommonLibSSE REQUIRED)
find_package(Detours REQUIRED)
find_package(nlohmann_json REQUIRED)

configure_file(cmake/plugin.h.in plugin.h)
configure_file(cmake/version.rc.in version.rc)

add_library("${PROJECT_NAME}" SHARED)

target_sources("${PROJECT_NAME}"
	PRIVATE
	src/init.cpp
	src/init.h
	src/main.cpp
	src/MenuOpenHandler.cpp
	src/MenuOpenHandler.h
	src/Offsets.h
	src/pch.h
	src/Settings.cpp
	src/Settings.h
	src/SettingsPapyrus.cpp
	src/SettingsPapyrus.h
	src/TESObjectREFR.cpp
	src/TESObjectREFR.h
	"${PROJECT_BINARY_DIR}/plugin.h"
	"${PROJECT_BINARY_DIR}/version.rc"
)

target_precompile_headers("${PROJECT_NAME}"
	PRIVATE
	src/pch.h
)

target_compile_features("${PROJECT_NAME}"
	PRIVATE
	cxx_std_20
)

target_include_directories("${PROJECT_NAME}"
	PRIVATE
	"${PROJECT_BINARY_DIR}"
)

target_link_libraries("${PROJECT_NAME}"
	PRIVATE
	CommonLibSSE::CommonLibSSE
	Detours::Detours
	nlohmann_json::nlohmann_json
)

install(TARGETS "${PROJECT_NAME}" RUNTIME DESTINATION "${SKYRIM_ROOT}/data/skse/plugins")