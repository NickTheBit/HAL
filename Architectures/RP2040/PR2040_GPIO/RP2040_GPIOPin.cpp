/*********************************************
 * @brief Hardware specific driver for the
 * GPIO pins of the RP2040.
 * @author Nikolaos Xenofon Gkloumpos
 * @date 25/05/2023
 *********************************************/

#include "RP2040_GPIOPin.hh"

/**
 * @brief Initializes the pin, sets the direction.
 * @param GPIOPin Pin number.
 * @param GPIODir Pin direction.
 */
RP2040_GPIOPin::RP2040_GPIOPin(uint8_t GPIOPin, uint8_t GPIODir)
	: pin(GPIOPin), direction(GPIODir) {
	gpio_init(this->pin);
	gpio_set_dir(this->pin, this->direction);
}

/**
 * @brief Reads the current state of the pin
 * @return State of the pin as GPIO_STATE.
 */
HAL::GPIO_STATE RP2040_GPIOPin::read() {
	return static_cast<HAL::GPIO_STATE>(gpio_get(this->pin));
}

/**
 * @brief Sets the pin to a desired state.
 * @param newState The state set.
 */
void RP2040_GPIOPin::write(HAL::GPIO_STATE newState) {
	gpio_put(this->pin, (uint8_t)newState);
}
