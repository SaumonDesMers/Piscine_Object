#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>

#include "engine.hpp"
#include "brakes.hpp"
#include "gearbox.hpp"
#include "steerwheel.hpp"

class Car {

public:

	/**
	 * @brief Starts the engine.
	 */
	void start() {
		this->_engine.start();
	}

	/**
	 * @brief Stops the engine and applies brakes.
	 */
	void stop() {
		this->_engine.stop();
		this->_brakes.full_stop();
	}

	/**
	 * @brief Increases the speed by a given amount.
	 * @param speed The amount to increase the speed by.
	 */
	void accelerate(float speed) {
		this->_engine.accelerate(speed);
	}

	/**
	 * @brief Shifts up to the next gear.
	 */
	void shift_gears_up() {
		this->_gearbox.shift_up();
	}

	/**
	 * @brief Shifts down to the previous gear.
	 */
	void shift_gears_down() {
		this->_gearbox.shift_down();
	}

	/**
	 * @brief Puts the transmission in reverse gear.
	 */
	void reverse() {
		this->_gearbox.reverse();
	}

	/**
	 * @brief Turns the wheel by a given angle.
	 * @param angle The angle to turn the wheel by.
	 */
	void turn_wheel(float angle) {
		this->_steerwheel.turn(angle);
	}

	/**
	 * @brief Returns the wheels to a straight-ahead position.
	 */
	void straighten_wheels() {
		this->_steerwheel.turn(0);
	}

	/**
	 * @brief Applies the brakes with a given force.
	 * @param force The force to apply the brakes with.
	 */
	void apply_force_on_brakes(float force) {
		this->_brakes.apply(force);
	}

	/**
	 * @brief Applies the brakes with maximum force for an emergency stop.
	 */
	void apply_emergency_brakes() {
		this->_brakes.full_stop();
	}

private:

	Engine _engine;
	Brakes _brakes;
	GearBox _gearbox;
	SteerWheel _steerwheel;

};

#endif // CAR_HPP