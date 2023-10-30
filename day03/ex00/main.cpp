#include "car.hpp"

int main() {
	Car car;

	car.start();
	car.accelerate(1000);
	car.shift_gears_up();
	car.turn_wheel(45);
	car.straighten_wheels();
	car.apply_force_on_brakes(0.5);
	car.shift_gears_down();
	car.reverse();
	car.stop();
	return 0;
}