#include "hammer.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;


Hammer::Hammer() : Tool() { LOG_FUNCTION }
Hammer::Hammer(int numberOfUses) : Tool(numberOfUses) { LOG_FUNCTION }
Hammer::~Hammer() { LOG_FUNCTION }

void Hammer::use() { LOG_FUNCTION
	if (this->_numberOfUses == 0)
		throw std::runtime_error("Hammer is broken");
	std::cout << "Hammering with a hammer" << std::endl;
	this->_numberOfUses--;
}