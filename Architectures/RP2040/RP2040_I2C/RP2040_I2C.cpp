/***********************************************
 * @brief  Hardware specific I2C wrapper for the RP2040.
 * @author Nikolaos Xenofon Gkloumpos.
 * @date   6/1/23
 ***********************************************/

#include "RP2040_I2C.h"
#include <hardware/gpio.h>
#include <pico/binary_info/code.h>

/**
 * @brief Initializes the necessary hardware for i2c communication.
 * @param hardwareInterface
 * @param slaveMode puts the interface in slave mode.
 * @param baudrateHz
 * @param responseTimeout
 */
RP2040_I2C::RP2040_I2C(i2c_inst_t *hardwareInterface, const uint8_t SDAPin, const uint8_t SCLPin, const bool slaveMode,
					   uint32_t baudrateHz, uint16_t timeout)
	: hardwareInterface(hardwareInterface), SCLPin(SCLPin), SDAPin(SDAPin), baudrateHz(baudrateHz),
	  slaveMode(slaveMode), commandTimeoutUs(timeout) {

	this->baudrateHz = i2c_init(this->hardwareInterface, this->baudrateHz);

	i2c_set_slave_mode(this->hardwareInterface, slaveMode, 0x33);

	gpio_set_function(this->SDAPin, GPIO_FUNC_I2C);
	gpio_set_function(this->SCLPin, GPIO_FUNC_I2C);
	gpio_pull_up(this->SDAPin);
	gpio_pull_up(this->SCLPin);
	bi_decl(bi_2pins_with_func((uint32_t)this->SDAPin, (uint32_t)this->SCLPin, GPIO_FUNC_I2C));
}

/**
 * @brief De-initializes i2c the interface.
 */
RP2040_I2C::~RP2040_I2C() {
	i2c_deinit(this->hardwareInterface);
}

/**
 * @brief Reads multiple bytes starting from the target slaveAddress.
 * @param slaveAddress
 * @param consecutiveBytes
 * @return
 */
I2CResult RP2040_I2C::readImpl(uint8_t slaveAddress, uint8_t consecutiveBytes, uint8_t *outputArray) {
	if (consecutiveBytes < 1) {
		return I2CResult::FAILURE;
	}
	const auto error = i2c_read_timeout_us(this->hardwareInterface, slaveAddress, outputArray, consecutiveBytes, false,
										   commandTimeoutUs);
	return convert_to_generic_error(error);
}

I2CResult RP2040_I2C::writeImpl(uint8_t slaveAddress, uint8_t *payload, uint16_t payloadSize) {
	if (payloadSize < 1) {
		return I2CResult::FAILURE;
	}
	const auto error =
		i2c_write_timeout_us(this->hardwareInterface, slaveAddress, payload, payloadSize, false, commandTimeoutUs);
	return convert_to_generic_error(error);
}

/**
 * @brief   Getter for the selected baud-rate (Hz).
 * @return  baudrateHz.
 */
uint16_t RP2040_I2C::getBaudrateHz() const {
	return this->baudrateHz;
}

/**
 * @brief   Getter for whether the interface is in slave mode.
 * @return  slaveMode.
 */
bool RP2040_I2C::isSlaveMode() const {
	return this->slaveMode;
}

/**
 * @brief  Converts architecture specific error codes to generic ones.
 * @return I2C Result code.
 */
I2CResult RP2040_I2C::convert_to_generic_error(const int localError) {
	if (localError == -3) {
		return I2CResult::TIMEOUT;
	}

	if (localError < 0) {
		return I2CResult::FAILURE;
	}
	return I2CResult::SUCCESS;
}
