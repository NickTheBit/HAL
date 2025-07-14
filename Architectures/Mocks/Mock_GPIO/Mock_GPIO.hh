/************************************************
* @brief   Mocks for hardware functions
 * @author  Nikolaos Xenofon Gkloumpos
 * @date    21/12/2022
 ************************************************/

#pragma once

#include <gmock/gmock.h>
#include "Interfaces/GPIOPinInterface.hh"

class Mock_GPIOPin : public HAL::GPIOPinInterface<Mock_GPIOPin> {
public:
	Mock_GPIOPin() {}

	MOCK_METHOD(void, writeImpl, (HAL::GPIO_STATE), ());
	MOCK_METHOD(HAL::GPIO_STATE , readImpl, (), ());
};

