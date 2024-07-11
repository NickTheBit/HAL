# Architecture selection occurs in this file, simply append additional architectures
# in the if else chain bellow.

if ("${HAL_SELECTED_ARCHITECTURE}" STREQUAL "RP2040")
	message(STATUS "HAL set to RP2040")
	add_subdirectory(RP2040/)
	target_link_libraries(HAL PUBLIC RP2040_Backend)

endif ()

