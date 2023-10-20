#include "shovel.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;


Shovel::Shovel() : _numberOfUses(0), _worker(NULL) { LOG_FUNCTION }
Shovel::Shovel(int numberOfUses) : _numberOfUses(numberOfUses), _worker(NULL) { LOG_FUNCTION }
Shovel::~Shovel() { LOG_FUNCTION }

int Shovel::getNumberOfUses() const { LOG_FUNCTION
	return _numberOfUses;
}

void Shovel::setNumberOfUses(int numberOfUses) { LOG_FUNCTION
	this->_numberOfUses = numberOfUses;
}

void Shovel::assign(Worker *worker) { LOG_FUNCTION
	if (!worker)
		throw std::runtime_error("Cannot assign NULL worker");
	if (this->_worker)
		this->_worker->removeShovel();
	this->_worker = worker;
	this->_worker->_shovel = this;
}

void Shovel::unassign() { LOG_FUNCTION
	if (this->_worker)
		this->_worker->_shovel = NULL;
	this->_worker = NULL;
}

void Shovel::use() { LOG_FUNCTION
	_numberOfUses--;
}