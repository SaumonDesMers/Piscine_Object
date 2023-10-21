#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>

#include "worker.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;

class Worker;

class Tool
{

	friend class Worker;

public:

	Tool();
	Tool(int numberOfUses);

	/**
	 * @brief Destroys the tool.
	 * 
	 * @details If the tool is assigned to a worker, unassigns the tool from the worker.
	 * 
	 */
	~Tool();

	/**
	 * @return The number of times this tool has been used.
	 * 
	 */
	int getNumberOfUses() const;

	/**
	 * @brief Sets the number of times this tool has been used.
	 * 
	 * @param numberOfUses The number of times this tool has been used.
	 */
	void setNumberOfUses(int numberOfUses);

	/**
	 * @brief Abstract method to use the tool. Must be implemented by subclasses.
	 * 
	 */
	virtual void use() = 0;

protected:

	/**
	 * @brief The number of times this tool has been used.
	 * 
	 */
	int _numberOfUses;

	/**
	 * @brief The worker that has this tool equipped.
	 * 
	 */
	Worker *_worker;

	/**
	 * @brief Assigns the tool to a worker. Unassigns the tool from the previous worker if it is assigned.
	 * 
	 * @param worker The worker to assign the tool to.
	 * 
	 * @throw std::runtime_error If the worker is NULL.
	 * @throw std::runtime_error If the tool is already assigned to the worker.
	 */
	void _assign(Worker *worker);

	/**
	 * @brief If the tool is assigned to a worker, calls the worker's _removeTool method.
	 * 			Then sets the worker to NULL.
	 * 			Otherwise does nothing.
	 * 
	 */
	void _unassign();

};

#endif // TOOL_HPP