#include "worker.hpp"

#include <iostream>
#include <vector>

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;


Worker::Worker() : position(), statistic() { LOG_FUNCTION }
Worker::~Worker() { LOG_FUNCTION
	std::vector<Tool *> tools;
	for (ToolSet::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it)
		tools.push_back(*it);
	for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it)
		(*it)->unassign();
	
	std::vector<Workshop *> workshops;
	for (WorkshopSet::iterator it = this->_workshops.begin(); it != this->_workshops.end(); ++it)
		workshops.push_back(*it);
	for (std::vector<Workshop *>::iterator it = workshops.begin(); it != workshops.end(); ++it)
		(*it)->removeWorker(this);
}

void Worker::addTool(Tool *tool) { LOG_FUNCTION
	if (!tool)
		throw std::runtime_error("Cannot add NULL tool");
	tool->assign(this);
}

void Worker::removeTool(Tool *tool) { LOG_FUNCTION
	if (this->_tools.find(tool) == this->_tools.end())
		throw std::runtime_error("Cannot remove unequipped tool");
	tool->unassign();
}

Worker::ToolSet const & Worker::getTools() const { LOG_FUNCTION
	return this->_tools;
}

void Worker::useTools() { LOG_FUNCTION
	for (ToolSet::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it)
		(*it)->use();
}

void Worker::enter(Workshop *workshop) { LOG_FUNCTION
	if (!workshop)
		throw std::runtime_error("Cannot enter NULL workshop");
	if (this->_workshops.find(workshop) != this->_workshops.end())
		throw std::runtime_error("Cannot enter workshop twice");
	workshop->addWorker(this);
}

void Worker::leave(Workshop *workshop) { LOG_FUNCTION
	if (!workshop)
		throw std::runtime_error("Cannot leave NULL workshop");
	if (this->_workshops.find(workshop) == this->_workshops.end())
		throw std::runtime_error("Cannot leave workshop that worker is not in");
	workshop->removeWorker(this);
}

void Worker::work() { LOG_FUNCTION
	this->useTools();
}