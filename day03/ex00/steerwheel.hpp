#ifndef STEERWHEEL_HPP
#define STEERWHEEL_HPP

#include <iostream>
#include <algorithm>

class SteerWheel {

public:

	/**
	 * @brief Turns the wheel by a given angle.
	 * @param angle The angle to turn the wheel by.
	 */
	void turn(float angle) {
		std::cout << "Steer wheel turned by " << angle << " degrees." << std::endl;
		this->_angle = std::max(-90.0f, std::min(90.0f, angle));
	}

private:

	float _angle;

};

#endif // STEERWHEEL_HPP