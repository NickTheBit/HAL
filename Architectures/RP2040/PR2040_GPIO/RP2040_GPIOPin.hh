/*********************************************
 * @brief Hardware specific driver for the
 * GPIO pins of the RP2040.
 * @author Nikolaos Xenofon Gkloumpos
 * @date 25/05/2023
 *********************************************/

#include "GPIOPinInterface.hh"
#include "hardware/gpio.h"

#pragma once

class RP2040_GPIOPin : public HAL::GPIOPinInterface {
  private:
	uint8_t pin = 0;
	uint8_t direction = GPIO_OUT;

  public:
	explicit RP2040_GPIOPin(uint8_t GPIOPin, uint8_t GPIODir);
	~RP2040_GPIOPin() = default;
	void write(HAL::GPIO_STATE) override;
	HAL::GPIO_STATE read() override;
};
