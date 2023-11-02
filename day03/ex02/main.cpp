#include <iostream>

#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void printShape(Shape const &shape, std::string const &name) {
	std::cout << "\033[1;34m" << name << "\033[0m" << std::endl;
	std::cout << "Area:      " << shape.area() << std::endl;
	std::cout << "Perimeter: " << shape.perimeter() << std::endl;
	std::cout << std::endl;
}

int main() {
	Shape shape;
	shape.addVertex(0, 0);
	shape.addVertex(1, 0);
	shape.addVertex(1, 1);
	shape.addVertex(0, 1);

	Circle circle(4);

	Rectangle rectangle(3, 5);

	Triangle triangle(0, 0, 1, 0, 0, 1);

	printShape(shape, "Shape");
	printShape(circle, "Circle");
	printShape(rectangle, "Rectangle");
	printShape(triangle, "Triangle");

	return 0;
}