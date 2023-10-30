#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>

class Engine {

public:

	/**
	 * @brief Starts the engine.
	 */
	void start() {
		std::cout << "Engine started." << std::endl;
		this->_rpm = 1000;
	}

	/**
	 * @brief Stops the engine.
	 */
	void stop() {
		std::cout << "Engine stopped." << std::endl;
		this->_rpm = 0;
	}

	/**
	 * @brief Increases the speed by a given amount.
	 * @param speed The amount to increase the speed by.
	 */
	void accelerate(float speed) {
		std::cout << "Engine accelerated by " << speed << " rmp." << std::endl;
		this->_rpm += speed;
	}

private:

	bool _rpm;

};

#endif // ENGINE_HPP