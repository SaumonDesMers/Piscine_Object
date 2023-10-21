#include "worker.hpp"

#include <iostream>
#include <vector>

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;


Worker::Worker() : position(), statistic() { LOG_FUNCTION }
Worker::~Worker() { LOG_FUNCTION
	while (!this->_tools.empty())
		this->dropTool(*this->_tools.begin());
	
	while (!this->_workshops.empty())
		this->leave(*this->_workshops.begin());
}

//##########################################
//#                                        #
//#             TOOL METHODS               #
//#									       #
//##########################################

void Worker::grabTool(Tool *tool) { LOG_FUNCTION
	if (!tool)
		throw std::runtime_error("Cannot add NULL tool");
	tool->_assign(this);
	this->_tools.insert(tool);
}

void Worker::dropTool(Tool *tool) { LOG_FUNCTION
	if (!tool)
		throw std::runtime_error("Cannot remove NULL tool");
	if (this->_tools.find(tool) == this->_tools.end())
		throw std::runtime_error("Cannot remove unequipped tool");
	tool->_unassign();
}

void Worker::_removeTool(Tool *tool) { LOG_FUNCTION
	if (this->_tools.find(tool) == this->_tools.end())
		throw std::runtime_error("Cannot remove unequipped tool");
	this->_tools.erase(tool);
	
	std::vector<Workshop *> workshopsToLeave;
	for (WorkshopSet::iterator it = this->_workshops.begin(); it != this->_workshops.end(); ++it) {
		if ((*it)->_isWorkerSuitable(this) == false)
			workshopsToLeave.push_back(*it);
	}
	for (std::vector<Workshop *>::iterator it = workshopsToLeave.begin(); it != workshopsToLeave.end(); ++it)
		(*it)->_removeWorker(this);
}

Worker::ToolSet const & Worker::getTools() const { LOG_FUNCTION
	return this->_tools;
}

void Worker::useTools() { LOG_FUNCTION
	for (ToolSet::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it)
		(*it)->use();
}

//##########################################
//#                                        #
//#           WORKSHOP METHODS             #
//#									       #
//##########################################

void Worker::enter(Workshop *workshop) { LOG_FUNCTION
	if (!workshop)
		throw std::runtime_error("Cannot enter NULL workshop");
	if (this->_workshops.find(workshop) != this->_workshops.end())
		throw std::runtime_error("Cannot enter workshop twice");
	workshop->_addWorker(this);
}

void Worker::leave(Workshop *workshop) { LOG_FUNCTION
	if (!workshop)
		throw std::runtime_error("Cannot leave NULL workshop");
	if (this->_workshops.find(workshop) == this->_workshops.end())
		throw std::runtime_error("Cannot leave workshop that worker is not in");
	workshop->_removeWorker(this);
}

void Worker::work() { LOG_FUNCTION
	this->useTools();
}