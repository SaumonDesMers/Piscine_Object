#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include <iostream>

#include "tool.hpp"
#include "worker.hpp"

class Shovel: public Tool
{

public:

	Shovel();
	Shovel(int numberOfUses);
	~Shovel();

	void use();

};

#endif // SHOVEL_HPP