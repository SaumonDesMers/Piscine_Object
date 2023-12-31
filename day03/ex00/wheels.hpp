#ifndef WHEELS_HPP
#define WHEELS_HPP

#include <iostream>

class Wheels {

public:

	Wheels(): _speed(0) {}

	/**
	 * @brief Accelerates the wheels by a given amount.
	 * @param speed The amount to increase the speed by.
	 */
	void set_speed(int speed) {
		std::cout << "Wheels speed set to " << speed << "." << std::endl;
		this->_speed = speed;
	}

	void brake(float force) {
		this->_speed = this->_speed * (1 - force);
		std::cout << "Wheels slowed down by " << force << " to " << this->_speed << "." << std::endl;
	}

	void turn(int angle) {
		std::cout << "Wheels turned to " << angle << " degrees." << std::endl;
		this->_angle = angle;
	}

private:

	int _speed;
	int _angle;

};

#endif // WHEELS_HPP