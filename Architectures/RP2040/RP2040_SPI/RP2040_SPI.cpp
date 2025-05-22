/***********************************************
 * @brief  Hardware specific SPI driver for RP2040
 * @author Nikolaos Xenofon Gkloumpos.
 * @date   22/05/2025
 ***********************************************/

#include "RP2040_SPI.hh"
#include "hardware/gpio.h"

RP2040_SPI::RP2040_SPI(spi_inst_t *hardware, const uint8_t sck_pin, const uint8_t mosi_pin, const uint8_t miso_pin,
					   const uint baudrate, spi_cpol_t const cpol, spi_cpha_t const cpha, spi_order_t const bit_order,
					   uint8_t const message_size)
	: hardware_interface(hardware), sck_pin(sck_pin), mosi_pin(mosi_pin), miso_pin(miso_pin), baudrate(baudrate),
	  cpol(cpol), cpha(cpha), bit_order(bit_order), message_size(message_size) {
	spi_init(hardware_interface, baudrate);
	spi_set_format(hardware_interface, message_size, cpol, cpha, bit_order);

	// Initialize SPI pins
	gpio_set_function(sck_pin, GPIO_FUNC_SPI);
	gpio_set_function(mosi_pin, GPIO_FUNC_SPI);
	gpio_set_function(miso_pin, GPIO_FUNC_SPI);
}

/**
 * @brief Reads data from the SPI bus, transmits zeros where needed to receive.
 * @param output_buffer Buffer to output received data
 * @param length Max length of the expected data
 * @return Size of data read.
 */
uint8_t RP2040_SPI::readImpl(uint8_t *output_buffer, const uint16_t length) {
	return spi_read_blocking(hardware_interface, 0, output_buffer, length);
}

/**
 * @brief Transmits data on the SPI bus.
 * @param message Array of data to be transmitted.
 * @param length Length of data to be transmitted.
 * @return Length of data actually transmitted.
 */
uint8_t RP2040_SPI::writeImpl(const uint8_t *message, const uint16_t length) {
	return spi_write_blocking(hardware_interface, message, length);
}
