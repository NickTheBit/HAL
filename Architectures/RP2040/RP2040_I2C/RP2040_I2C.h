/***********************************************
 * @brief  Hardware specific I2C wrapper for the RP2040.
 * @author Nikolaos Xenofon Gkloumpos.
 * @date   6/1/23
 ***********************************************/

#pragma once

#include "I2CInterface.hh"
#include "hardware/i2c.h"

class RP2040_I2C : public I2CInterface<RP2040_I2C> {
  private:
	i2c_inst_t *hardwareInterface;
	uint8_t SCLPin;
	uint8_t SDAPin;
	uint16_t baudrateHz;
	bool slaveMode;
	static I2CResult convert_to_generic_error(int);
  public:
	RP2040_I2C(i2c_inst_t *hardwareInterface, uint8_t SDAPin, uint8_t SCLPin,
			   bool slaveMode, uint32_t baudrateHz);
	~RP2040_I2C();
	I2CResult readImpl(uint8_t slaveAddress, uint8_t consecutiveBytes, uint8_t *outputArray, bool nostop);
	I2CResult writeImpl(uint8_t slaveAddress, uint8_t *payload, uint16_t payloadSize, bool nostop);
	uint16_t getBaudrateHz() const;
	bool isSlaveMode() const;
};
