#include "tool.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;


Tool::Tool() : _numberOfUses(0), _worker(NULL) { LOG_FUNCTION }
Tool::Tool(int numberOfUses) : _numberOfUses(numberOfUses), _worker(NULL) { LOG_FUNCTION }
Tool::~Tool() { LOG_FUNCTION
	if (this->_worker)
		this->_unassign();
}

int Tool::getNumberOfUses() const { LOG_FUNCTION
	return _numberOfUses;
}

void Tool::setNumberOfUses(int numberOfUses) { LOG_FUNCTION
	this->_numberOfUses = numberOfUses;
}

void Tool::_assign(Worker *worker) { LOG_FUNCTION
	if (!worker)
		throw std::runtime_error("Cannot assign NULL worker");
	if (this->_worker == worker)
		throw std::runtime_error("Cannot assign tool to the same worker twice");
	if (this->_worker)
		this->_unassign();
	this->_worker = worker;
}

void Tool::_unassign() { LOG_FUNCTION
	this->_worker->_removeTool(this);
	this->_worker = NULL;
}