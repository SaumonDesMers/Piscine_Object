#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>

#include "shape.hpp"

class Rectangle: public Shape {

public:

	Rectangle(float width, float height): _width(width), _height(height) {}

	float area() const {
		return _width * _height;
	}

	float perimeter() const {
		return 2 * (_width + _height);
	}

private:

	float _width;
	float _height;

};

#endif // RECTANGLE_HPP