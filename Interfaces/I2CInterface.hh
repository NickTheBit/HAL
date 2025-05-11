/*********************************************
 * @brief Interface allowing a universal driver I2C
 *        across architectures
 * @author Nikolaos Xenofon Gkloumpos
 * @date 25/05/2023
 *********************************************/

#pragma once

#include <cstdint>

enum class I2CResult { SUCCESS = 0, FAILURE = 1, TIMEOUT = 2 };

template <typename Arch> class I2CInterface {
  public:
	I2CResult read(uint8_t address, uint16_t consecutiveBytes, uint8_t *outputArray) {
		return static_cast<Arch *>(this)->readImpl(address, consecutiveBytes, outputArray);
	}
	I2CResult write(uint8_t address, uint8_t *payload, uint16_t payloadSize) {
		return static_cast<Arch *>(this)->writeImpl(address, payload, payloadSize);
	}
};