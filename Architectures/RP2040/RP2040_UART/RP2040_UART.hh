/**********************************************
 * @brief
 * @author RP2040_UART
 * @date   7/11/24
 **********************************************/

#pragma once

#include "UARTInterface.hh"
#include <hardware/uart.h>


class RP2040_UART : public HAL::UARTInterface {
  private:
	uart_inst & busInstance;
	const uint32_t baudRate;
  public:
	RP2040_UART(uart_inst &bus, uint32_t baudRate);
	~RP2040_UART() = default;
	void write(std::string message) override;
	void read() override;
};
