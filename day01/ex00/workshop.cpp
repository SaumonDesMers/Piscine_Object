#include "workshop.hpp"

#include <iostream>
#include <vector>

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;


Workshop::Workshop() { LOG_FUNCTION }
Workshop::~Workshop() { LOG_FUNCTION
	while (!this->_workers.empty()) {
		Worker *worker = *this->_workers.begin();
		this->_workers.erase(worker);
		worker->_workshops.erase(this);
	}
}

void Workshop::_addWorker(Worker *worker) { LOG_FUNCTION
	if (!worker)
		throw std::runtime_error("Cannot add NULL worker");
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