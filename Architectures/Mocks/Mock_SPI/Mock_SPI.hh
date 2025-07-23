/*********************************************
 * @brief   Mock for the SPI bus.
 * @author Nikolaos Xenofon Gkloumpos
 * @date   14/07/2025
 *********************************************/

#pragma once

#include "Interfaces/SPIInterface.hh"
#include <gmock/gmock.h>

class Mock_SPI : public SPIInterface<Mock_SPI> {
  public:
	Mock_SPI() {}

	MOCK_METHOD(uint8_t, writeImpl, (uint8_t *message, uint16_t length), ());
	MOCK_METHOD(uint8_t, readImpl, (uint8_t *output_buffer, uint16_t length), ());
	MOCK_METHOD(uint8_t, transferImpl, (uint8_t *outgoing_buffer, uint8_t *incoming_buffer, uint16_t length), ());
};
