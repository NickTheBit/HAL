/**********************************************
 * @brief
 * @author RP2040_UART
 * @date   7/11/24
 **********************************************/

#pragma once

#include "UARTInterface.hh"

class RP2040_UART : public HAL::UARTInterface {
  public:
	RP2040_UART() = default;
	~RP2040_UART() = default;
	void write(std::string message) override;
	void read() override;
};
