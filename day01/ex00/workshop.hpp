#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include "worker.hpp"

class Worker;

class Workshop
{
	friend class Worker;

public:

	typedef std::set<Worker *> WorkerSet;

	Workshop();

	/**
	 * @brief Destroys the workshop.
	 * 
	 * @details Removes all the workers from the workshop.
	 * 
	 */
	~Workshop();

	/**
	 * @brief Executes a work day for all the workers in the workshop.
	 * 
	 */
	void executeWorkDay();

private:

	/**
	 * @brief The set of workers in the workshop.
	 * 
	 */
	WorkerSet _workers;

	/**
	 * @brief Adds a worker to the workshop.
	 * 
	 * @param worker The worker to add. 
	 */
	void _addWorker(Worker *worker);

	/**
	 * @brief Removes a worker from the workshop.
	 * 
	 * @param worker The worker to remove.
	 */
	void _removeWorker(Worker *worker);

};

#endif // WORKSHOP_HPP