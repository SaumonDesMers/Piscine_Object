#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>

#include "gearbox.hpp"

class Engine {

public:

	Engine(): _rpm(0) {}

	/**
	 * @brief Starts the engine.
	 */
	void start() {
		std::cout << "Engine started." << std::endl;
		this->accelerate(1000);
	}

	/**
	 * @brief Stops the engine.
	 */
	void stop() {
		std::cout << "Engine stopped." << std::endl;
		this->accelerate(-this->_rpm);
	}

	/**
	 * @brief Increases the speed by a given amount.
	 * @param speed The amount to increase the speed by.
	 */
	void accelerate(int speed) {
		std::cout << "Engine accelerated by " << speed << " rmp." << std::endl;
		this->_rpm += speed;
		this->transmit();
	}

	/**
	 * @brief Transmits the current RPM to the gearbox.
	 */
	void transmit() {
		std::cout << "Engine transmitting " << this->_rpm << " rpm." << std::endl;
		this->_gearbox->transmit(this->_rpm);
	}

	/**
	 * @brief Sets the gearbox to use.
	 */
	void set_gearbox(GearBox *gearbox) {
		this->_gearbox = gearbox;
	}

private:

	int _rpm;
	GearBox *_gearbox;

};

#endif // ENGINE_HPP