/**********************************************
 * @brief
 * @author RP2040_UART
 * @date   7/11/24
 **********************************************/

#include "RP2040_UART.hh"
#include <pico/stdlib.h>

RP2040_UART::RP2040_UART(uart_inst &bus, uint32_t baudRate)
	: busInstance(bus), baudRate(baudRate) {
	// todo: Passing instance like this? wtf?
	setup_default_uart();
	uart_init(&this->busInstance, baudRate);
	// todo: verify this is needed, get a uart converter.
	//	gpio_set_function(4, GPIO_FUNC_UART);
}

/**
 * @brief Writes a message out to the selected uart bus.
 * @param message String to be written out.
 * @note todo: Convert to using simple c array to be usable in low level.
 */
void RP2040_UART::write(std::string message) {
	uart_puts(&this->busInstance, message.c_str());
}

/**
 * @brief Reads a line from an incomming uart message.
 * @note Probably :)
 */
void RP2040_UART::read() {
}
