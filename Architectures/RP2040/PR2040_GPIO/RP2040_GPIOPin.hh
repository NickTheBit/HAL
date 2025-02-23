/*********************************************
 * @brief Hardware specific driver for the
 * GPIO pins of the RP2040.
 * @author Nikolaos Xenofon Gkloumpos
 * @date 25/05/2023
 *********************************************/
#pragma once

#include "GPIOPinInterface.hh"
#include "hardware/gpio.h"

class RP2040_GPIOPin : public HAL::GPIOPinInterface<RP2040_GPIOPin>
{
private:
    uint8_t pin = 0;
    uint8_t direction = GPIO_OUT;

public:
    /**
     * @brief Initializes the pin, sets the direction.
     * @param GPIOPin Pin.
     * @param GPIODir Pin direction.
     */
    RP2040_GPIOPin(const uint8_t GPIOPin, const uint8_t GPIODir)
        : pin(GPIOPin), direction(GPIODir) {
        gpio_init(this->pin);
        gpio_set_dir(this->pin, this->direction);
    }

    /**
     * @brief Sets the pin to a desired state.
     * @param newState The state set.
     */
    void writeImpl(HAL::GPIO_STATE newState) {
        gpio_put(this->pin, (uint8_t)newState);
    }

    /**
    * @brief Reads the current state of the pin
    * @return State of the pin as GPIO_STATE.
    */
    HAL::GPIO_STATE readImpl() {
        return static_cast<HAL::GPIO_STATE>(gpio_get(this->pin));
    }
};
