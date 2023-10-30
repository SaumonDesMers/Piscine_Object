#ifndef GEARBOX_HPP
#define GEARBOX_HPP

#include <iostream>

class GearBox {

public:

	/**
	 * @brief Shifts up to the next gear.
	 */
	void shift_up() {
		if (this->_gearLevel == 5) {
			std::cout << "Gear already at maximum." << std::endl;
			return;
		}
		std::cout << "Gear shifted up." << std::endl;
		this->_gearLevel++;
	}

	/**
	 * @brief Shifts down to the previous gear.
	 */
	void shift_down() {
		if (this->_gearLevel == 0) {
			std::cout << "Gear already at minimum." << std::endl;
			return;
		}
		std::cout << "Gear shifted down." << std::endl;
		this->_gearLevel--;
	}

	/**
	 * @brief Puts the transmission in reverse gear.
	 */
	void reverse() {
		if (this->_gearLevel == -1) {
			std::cout << "Gear shifted back to normal." << std::endl;
			this->_gearLevel = 1;
			return;
		}
		std::cout << "Gear shifted to reverse." << std::endl;
		this->_gearLevel = -1;
	}

private:

	int _gearLevel;

};

#endif // GEARBOX_HPP