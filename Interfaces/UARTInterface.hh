/**********************************************
 * @brief Uard abstraction interface
 * @author Nikolaos Xenofon Gkloumpos
 * @date   7/11/24
 **********************************************/

#pragma once

#include <string>

namespace HAL {

template <typename Arch>  class UARTInterface {
  public:
	/* todo: An override avoiding the strign library should exist. */
	void write(std::string message) {
		static_cast<Arch *>(this)->writeImpl(message);
	}
	void read() {
		static_cast<Arch *>(this)->readImpl();
	}
};

} // namespace HAL