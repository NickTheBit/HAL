/**********************************************
 * @brief Uard abstraction interface
 * @author Nikolaos Xenofon Gkloumpos
 * @date   7/11/24
 **********************************************/

#pragma once

#include <string>

namespace HAL {

class UARTInterface {
  public:
	virtual void write(std::string message) = 0;
	virtual void read() = 0;
};

} // namespace HAL