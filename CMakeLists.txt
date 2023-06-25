# Hardware Abstraction Library build file
# Intended to be configured based on a single architecture and compile only the relevant source files.

# Absolute path to FreeRTOS config file directory
set(HAL_SELECTED_ARCHITECTURE "" CACHE STRING "The selected architecture to be used by the library.")

set(HAL_SOURCES "")
file(GLOB_RECURSE HAL_SOURCES Interfaces/*.hh)

add_library(HAL STATIC ${HAL_SOURCES})
set_target_properties(HAL PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(HAL PUBLIC Interfaces/)

if(NOT HAL_SELECTED_ARCHITECTURE)
    message(FATAL_ERROR "No HAL architecture was selected.")
else()
    add_subdirectory(Architectures/)
endif()
