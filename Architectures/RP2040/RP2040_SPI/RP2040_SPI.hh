/***********************************************
 * @brief  Hardware specific SPI driver for RP2040
 * @author Nikolaos Xenofon Gkloumpos.
 * @date   22/05/2025
 ***********************************************/

#pragma once

#include "SPIInterface.hh"
#include "hardware/spi.h"

class RP2040_SPI : public SPIInterface<RP2040_SPI> {
  private:
	spi_inst_t * hardware_interface;
	uint8_t sck_pin;
	uint8_t mosi_pin;
	uint8_t miso_pin;
	uint baudrate;
	spi_cpol_t cpol;
	spi_cpha_t cpha;
	spi_order_t bit_order;
	uint8_t message_size;

  public:
	explicit RP2040_SPI(spi_inst_t * hardware, uint8_t sck_pin, uint8_t mosi_pin, uint8_t miso_pin, uint baudrate, spi_cpol_t cpol,
			   spi_cpha_t cpha, spi_order_t bit_order, uint8_t message_size);
	~RP2040_SPI() = default;
	uint8_t writeImpl(const uint8_t *message, uint16_t length);
	uint8_t readImpl(uint8_t *output_buffer, uint16_t length);
};