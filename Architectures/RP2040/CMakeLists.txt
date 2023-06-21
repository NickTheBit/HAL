# RP2040 Build file

# Pull in SDK
include(cmakeScripts/pico_sdk_import.cmake)
include(cmakeScripts/pico_extras_import_optional.cmake)

file(GLOB_RECURSE RP2040_SOURCES ./*.cpp)

add_library(RP2040_Backend STATIC ${RP2040_SOURCES})

target_link_libraries(RP2040_Backend LINK_PUBLIC
        pico_stdlib
        hardware_i2c)