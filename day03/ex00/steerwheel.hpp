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
	void turn(float angle) {
		std::cout << "Steer wheel turned to " << angle << " degrees." << std::endl;
		this->_angle = std::max(-90.0f, std::min(90.0f, angle));
	}

	/**
	 * @brief Sets the wheels to turn.
	 */
	void set_wheels(Wheels *wheels) {
		this->_wheels = wheels;
	}

private:

	float _angle;
	Wheels *_wheels;

};

#endif // STEERWHEEL_HPP