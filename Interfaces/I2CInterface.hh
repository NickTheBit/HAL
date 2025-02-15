/*********************************************
 * @brief Interface allowing a universal driver I2C
 *        across architectures
 * @author Nikolaos Xenofon Gkloumpos
 * @date 25/05/2023
 *********************************************/

#pragma once

#include <cstdint>

template <typename Arch> class I2CInterface {
  public:
	void read(uint8_t address, uint8_t consecutiveBytes, uint8_t *outputArray) {
		static_cast<Arch *>(this)->readImpl(address, consecutiveBytes, outputArray);
	}
	void write(uint8_t address, uint8_t *payload, uint16_t payloadSize) {
		static_cast<Arch *>(this)->writeImpl(address, payload, payloadSize);
	}
};