/*********************************************
* @brief   Interface for common functions of
 *         an SPI bus across architectures
 * @author Nikolaos Xenofon Gkloumpos
 * @date   22/05/2025
 *********************************************/

#pragma once

#include <cstdint>

template <typename Arch> class SPIInterface {
public:
	uint8_t write(uint8_t * message, uint16_t length) {
		return static_cast<Arch *>(this)->writeImpl(message, length);
	}
	uint8_t read(uint8_t * output_buffer, uint8_t length) {
		return static_cast<Arch *>(this)->readImpl(output_buffer, length);
	}
};