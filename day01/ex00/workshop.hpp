#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include "worker.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;

class Worker;
class Tool;

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

	/**
	 * @brief Sets the tool that is restricted to this workshop.
	 * 
	 * @tparam T The type of the tool.
	 */
	template <typename ToolType>
	void setRestrictedTool() { LOG_FUNCTION
		if (this->_restrictedTool)
			this->removeRestrictedTool();
		this->_restrictedTool = new ToolType();
		this->_removeUnsuitableWorkers();
	}

	/**
	 * @brief Removes the restricted tool from the workshop.
	 * 
	 */
	void removeRestrictedTool();

private:

	/**
	 * @brief The set of workers in the workshop.
	 * 
	 */
	WorkerSet _workers;

	/**
	 * @brief The tool that is restricted to this workshop.
	 * 
	 */
	Tool *_restrictedTool;

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

	/**
	 * @brief Checks if a worker can enter the workshop.
	 * 
	 * @param worker The worker to check.
	 * @return true if the worker can enter the workshop.
	 * @return false if the worker cannot enter the workshop.
	 */
	bool _isWorkerSuitable(Worker *worker) const;

	/**
	 * @brief Removes all the workers that cannot enter the workshop.
	 * 
	 */
	void _removeUnsuitableWorkers();

};

#endif // WORKSHOP_HPP