# Hardware Abstraction Library build file
# Intended to be configured based on a single architecture and compile only the relevant source files.

# Absolute path to FreeRTOS config file directory
set(HAL_SELECTED_ARCHITECTURE "" CACHE STRING "The selected architecture to be used by the library.")

set(HAL_SOURCES "")

# TODO: Create dynamic including of sources depending on architecture.
if(NOT HAL_SELECTED_ARCHITECTURE)
    message(FATAL_ERROR "No HAL architecture was selected.")
elseif ("${HAL_SELECTED_ARCHITECTURE}" STREQUAL "RP2040")
    message(STATUS "HAL set to RP2040")
    file(GLOB_RECURSE HAL_SOURCES Architectures/RP2040/*.cpp)
endif ()


add_library(HAL STATIC ${HAL_SOURCES})
target_include_directories(HAL PUBLIC Interfaces/)
