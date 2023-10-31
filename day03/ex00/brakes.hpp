#ifndef BRAKES_HPP
#define BRAKES_HPP

#include <iostream>
#include <algorithm>

#include "wheels.hpp"

class Brakes {

public:

	/**
	 * @brief Applies the brakes with a given force.
	 * @param force The force to apply the brakes with.
	 */
	void apply(float force) {
		std::cout << "Brakes applied with a force of " << force << "." << std::endl;
		float clampedForce = std::max(0.0f, std::min(1.0f, force));
		this->_wheels->brake(clampedForce);
	}

	/**
	 * @brief Fully applies the brakes.
	*/
	void full_stop() {
		this->apply(1);
	}

	/**
	 * @brief Sets the wheels to apply the brakes to.
	 */
	void set_wheels(Wheels *wheels) {
		this->_wheels = wheels;
	}

private:

	Wheels *_wheels;

};

#endif // BRAKES_HPP