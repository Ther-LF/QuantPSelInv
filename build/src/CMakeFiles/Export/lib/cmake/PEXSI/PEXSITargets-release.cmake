#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "PEXSI::PEXSI" for configuration "Release"
set_property(TARGET PEXSI::PEXSI APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(PEXSI::PEXSI PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX;Fortran"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libpexsi.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS PEXSI::PEXSI )
list(APPEND _IMPORT_CHECK_FILES_FOR_PEXSI::PEXSI "${_IMPORT_PREFIX}/lib/libpexsi.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
