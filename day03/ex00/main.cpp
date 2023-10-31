#include "car.hpp"

#define NL std::cout << std::endl;

int main() {
	Car car;

	car.start();
	NL
	car.shift_gears_up();
	NL
	car.accelerate(1000);
	NL
	car.turn_wheel(45);
	NL
	car.straighten_wheels();
	NL
	car.apply_force_on_brakes(0.5);
	NL
	car.shift_gears_down();
	NL
	car.reverse();
	NL
	car.stop();
	return 0;
}

/*
@startuml

class Car
Car *-- Brakes
Car *-- Engine
Car *-- SteerWheel
Car *-- Gearbox
Car *-- Wheels

class Wheels

class Gearbox {
    -gearLevel
}
Gearbox o-- Wheels

class Engine {
    -rpm
}
Engine o-- Gearbox

class Brakes {
    -force
}
Brakes o-- Wheels

class SteerWheel {
    -direction
}
SteerWheel o-- Wheels

@enduml
*/