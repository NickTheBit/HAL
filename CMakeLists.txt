# Hardware Abstraction Library build file
# Intended to be configured based on a single architecture and compile only the relevant source files.

# Absolute path to FreeRTOS config file directory
set(HAL_SELECTED_ARCHITECTURE "" CACHE STRING "The selected architecture to be used by the library.")

set(HAL_SOURCES "")
file(GLOB_RECURSE HAL_SOURCES Interfaces/*.hh)

add_library(HAL STATIC ${HAL_SOURCES})
set_target_properties(HAL PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(HAL PUBLIC Interfaces/)

# TODO: Create dynamic including of sources depending on architecture.
if(NOT HAL_SELECTED_ARCHITECTURE)
    message(FATAL_ERROR "No HAL architecture was selected.")
elseif ("${HAL_SELECTED_ARCHITECTURE}" STREQUAL "RP2040")
    message(STATUS "HAL set to RP2040")
    add_subdirectory(Architectures/RP2040)
    target_link_libraries(HAL PUBLIC RP2040_Backend)

endif ()



