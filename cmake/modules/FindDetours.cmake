find_path(Detours_INCLUDE_DIRS "detours/detours.h")
find_library(Detours_LIBRARY_RELEASE detours REQUIRED)
find_library(Detours_LIBRARY_DEBUG detoursd REQUIRED)

include(SelectLibraryConfigurations)
select_library_configurations(Detours)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Detours
	FOUND_VAR Detours_FOUND
	REQUIRED_VARS
		Detours_LIBRARY
		Detours_INCLUDE_DIRS
)

if (Detours_FOUND)
	add_library(Detours::Detours STATIC IMPORTED)
	if (Detours_LIBRARY_RELEASE)
		set_property(TARGET Detours::Detours APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
		set_target_properties(Detours::Detours PROPERTIES IMPORTED_LOCATION_RELEASE "${Detours_LIBRARY_RELEASE}")
	endif()
	if (Detours_LIBRARY_DEBUG)
		set_property(TARGET Detours::Detours APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
		set_target_properties(Detours::Detours PROPERTIES IMPORTED_LOCATION_DEBUG "${Detours_LIBRARY_DEBUG}")
	endif()
	set_target_properties(Detours::Detours PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${Detours_INCLUDE_DIRS}")
endif()