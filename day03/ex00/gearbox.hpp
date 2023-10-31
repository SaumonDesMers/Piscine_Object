#ifndef GEARBOX_HPP
#define GEARBOX_HPP

#include <iostream>

#include "wheels.hpp"

class GearBox {

public:

	GearBox(): _gearLevel(0) {}

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

	/**
	 * @brief Transmits the engine speed to the wheels.
	 */
	void transmit(int speed) {
		if (this->_gearLevel == 0) {
			std::cout << "Gearbox not in gear." << std::endl;
			return;
		}
		std::cout << "Gearbox transmitting " << speed << " rpm with gear level " << this->_gearLevel << "." << std::endl;
		this->_wheels->set_speed(speed * this->_gearLevel);
	}

	/**
	 * @brief Sets the wheels to use.
	 */
	void set_wheels(Wheels *wheels) {
		this->_wheels = wheels;
	}

private:

	int _gearLevel;
	Wheels *_wheels;

};

#endif // GEARBOX_HPP