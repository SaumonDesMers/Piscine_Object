#include "shovel.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;


Shovel::Shovel() : Tool() { LOG_FUNCTION }
Shovel::Shovel(int numberOfUses) : Tool(numberOfUses) { LOG_FUNCTION }
Shovel::~Shovel() { LOG_FUNCTION }

void Shovel::use() { LOG_FUNCTION
	std::cout << "Digging with a shovel" << std::endl;
	this->_numberOfUses--;
}