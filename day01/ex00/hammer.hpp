#ifndef HAMMER_HPP
#define HAMMER_HPP

#include <iostream>

#include "tool.hpp"
#include "worker.hpp"

class Hammer: public Tool
{

public:

	Hammer();
	Hammer(int numberOfUses);
	~Hammer();

	void use();

};

#endif // HAMMER_HPP