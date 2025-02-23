/**********************************************
 * @brief
 * @author RP2040_UART
 * @date   7/11/24
 **********************************************/

#pragma once

#include "UARTInterface.hh"
#include <hardware/uart.h>
#include <pico/stdlib.h>


class RP2040_UART : public HAL::UARTInterface<RP2040_UART> {
private:
	uart_inst &busInstance;
	const uint32_t baudRate;

public:
	RP2040_UART(uart_inst &bus, uint32_t baudRate)
		: busInstance(bus), baudRate(baudRate) {
		// todo: Passing instance like this? wtf?
		setup_default_uart();
		uart_init(&this->busInstance, baudRate);
		// todo: verify this is needed, get a uart converter.
		//	gpio_set_function(4, GPIO_FUNC_UART);
	}

	~RP2040_UART() = default;

	/**
	 * @brief Writes a message out to the selected uart bus.
	 * @param message String to be written out.
	 * @note todo: Convert to using simple c array to be usable in low level.
	 */
	void writeImpl(std::string message) {
		uart_puts(&this->busInstance, message.c_str());
	}

	/**
	* @brief Reads a line from an incomming uart message.
	* @note Probably :)
	* fixme: Implement
	*/
	void readImpl() {

	}
};