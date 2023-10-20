#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include "worker.hpp"

class Worker;

class Workshop
{
public:

	typedef std::set<Worker *> WorkerSet;

	Workshop();
	~Workshop();

	void addWorker(Worker *worker);
	void removeWorker(Worker *worker);

	void executeWorkDay();

private:

	std::set<Worker *> _workers;

};

#endif // WORKSHOP_HPP