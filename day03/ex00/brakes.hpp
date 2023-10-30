#ifndef BRAKES_HPP
#define BRAKES_HPP

#include <iostream>
#include <algorithm>

class Brakes {

public:

	/**
	 * @brief Applies the brakes with a given force.
	 * @param force The force to apply the brakes with.
	 */
	void apply(float force) {
		std::cout << "Brakes applied with a force of " << force << "." << std::endl;
		this->_force = std::max(0.0f, std::min(1.0f, force));
	}

	/**
	 * @brief Fully applies the brakes.
	*/
	void full_stop() {
		this->apply(1);
	}

private:

	float _force;

};

#endif // BRAKES_HPP