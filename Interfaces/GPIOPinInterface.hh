/*********************************************
 * @brief Interface allowing a universal driver for
 * standard pin functions along multiple architectures.
 * @author Nikolaos Xenofon Gkloumpos
 * @date 25/05/2023
 *********************************************/

#pragma once

namespace HAL {

typedef enum { HIGH = 1, LOW = 0 } GPIO_STATE;

template <typename Arch> class GPIOPinInterface {
  public:
	void write(GPIO_STATE newState) {
		static_cast<Arch *>(this)->writeImpl(newState);
	}
	GPIO_STATE read() {
		return static_cast<Arch *>(this)->readImpl();
	}
};

} // namespace HAL
