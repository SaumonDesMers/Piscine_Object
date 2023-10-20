#include "worker.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;


Worker::Worker() : position(), statistic(), _shovel(NULL) { LOG_FUNCTION }

void Worker::addShovel(Shovel *shovel) { LOG_FUNCTION
	if (!shovel)
		throw std::runtime_error("Cannot add NULL shovel");
	shovel->assign(this);
}

void Worker::removeShovel() { LOG_FUNCTION
	if (this->_shovel)
		this->_shovel->unassign();
}

void Worker::dig() { LOG_FUNCTION
	if (!this->_shovel)
		throw std::runtime_error("Worker has no shovel");
	this->_shovel->use();
}