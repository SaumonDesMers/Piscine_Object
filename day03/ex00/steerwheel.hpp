#ifndef STEERWHEEL_HPP
#define STEERWHEEL_HPP

#include <iostream>
#include <algorithm>

#include "wheels.hpp"

class SteerWheel {

public:

	/**
	 * @brief Turns the wheel by a given angle.
	 * @param angle The angle to turn the wheel by.
	 */
	void turn(int angle) {
		std::cout << "Steer wheel turn wheels to " << angle << " degrees." << std::endl;
		int clamped_angle = std::max(-90, std::min(90, angle));
		this->_wheels->turn(clamped_angle);
	}

	/**
	 * @brief Sets the wheels to turn.
	 */
	void set_wheels(Wheels *wheels) {
		this->_wheels = wheels;
	}

private:

	Wheels *_wheels;

};

#endif // STEERWHEEL_HPP