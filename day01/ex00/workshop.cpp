#include "workshop.hpp"

#include <iostream>
#include <vector>
#include <typeinfo>

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;


Workshop::Workshop(): _restrictedTool(NULL) { LOG_FUNCTION }
Workshop::~Workshop() { LOG_FUNCTION
	while (!this->_workers.empty()) {
		Worker *worker = *this->_workers.begin();
		this->_workers.erase(worker);
		worker->_workshops.erase(this);
	}
	delete this->_restrictedTool;
}

void Workshop::_addWorker(Worker *worker) { LOG_FUNCTION
	if (!worker)
		throw std::runtime_error("Cannot add NULL worker");
	if (this->_workers.find(worker) != this->_workers.end())
		throw std::runtime_error("Cannot add worker twice");
	if (this->_isWorkerSuitable(worker) == false)
		throw std::runtime_error("Cannot add worker to workshop with restricted tool");
	this->_workers.insert(worker);
	worker->_workshops.insert(this);
}

void Workshop::_removeWorker(Worker *worker) { LOG_FUNCTION
	if (this->_workers.find(worker) == this->_workers.end())
		throw std::runtime_error("Cannot remove worker that is not in the workshop");
	this->_workers.erase(worker);
	worker->_workshops.erase(this);
}

void Workshop::executeWorkDay() { LOG_FUNCTION
	for (WorkerSet::iterator it = this->_workers.begin(); it != this->_workers.end(); ++it)
		(*it)->work();
}

void Workshop::removeRestrictedTool() { LOG_FUNCTION
	delete this->_restrictedTool;
	this->_restrictedTool = NULL;
}

bool Workshop::_isWorkerSuitable(Worker *worker) const { LOG_FUNCTION
	if (this->_restrictedTool) {
		Worker::ToolSet const &tools = worker->getTools();
		for (Worker::ToolSet::const_iterator it = tools.begin(); it != tools.end(); ++it){
			Tool *workerTool = *it;
			if (typeid(*workerTool) == typeid(*this->_restrictedTool))
				return true;
		}
		return false;
	}
	return true;
}

void Workshop::_removeUnsuitableWorkers() { LOG_FUNCTION
	std::vector<Worker *> workersToLeave;
	for (WorkerSet::iterator it = this->_workers.begin(); it != this->_workers.end(); ++it) {
		if (this->_isWorkerSuitable(*it) == false)
			workersToLeave.push_back(*it);
	}
	for (std::vector<Worker *>::iterator it = workersToLeave.begin(); it != workersToLeave.end(); ++it)
		this->_removeWorker(*it);
}