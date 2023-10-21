#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <set>

#include "position.hpp"
#include "statistic.hpp"
#include "tool.hpp"
#include "workshop.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;

class Tool;
class Workshop;

class Worker
{
	friend class Tool;
	friend class Workshop;

public:

	typedef std::set<Tool *> ToolSet;
	typedef std::set<Workshop *> WorkshopSet;

	Position position;
	Statistic statistic;

	Worker();

	/**
	 * @brief Destroys the worker.
	 * 
	 * @details Drops all the tools the worker has and leaves all the workshops the worker is in.
	 * 
	 */
	~Worker();

	/**
	 * @brief Adds a tool to the worker's toolset.
	 * 
	 * @param tool The tool to grab.
	 */
	void grabTool(Tool *tool);

	/**
	 * @brief Removes a tool from the worker's toolset.
	 * 
	 * @details The tool must be equipped.
	 * 
	 * @param tool The tool to drop.
	 * 
	 * @throw std::runtime_error If the tool is not equipped.
	 * @throw std::runtime_error If the tool is NULL.
	 */
	void dropTool(Tool *tool);

	/**
	 * @brief Returns the worker's toolset.
	 * 
	 * @return ToolSet const & The worker's toolset.
	 */
	ToolSet const & getTools() const;

	/**
	 * @brief Get the Tool object of the specified type.
	 * 
	 * @tparam ToolType must be a subclass of Tool.
	 * @return Tool * or NULL if the worker does not have a tool of the specified type.
	 */
	template <typename ToolType>
	Tool * getTool() const { LOG_FUNCTION
		for (ToolSet::iterator it = this->_tools.begin(); it != this->_tools.end(); ++it)
			if (dynamic_cast<ToolType *>(*it))
				return *it;
		return NULL;
	}

	/**
	 * @brief Uses all the tools the worker has.
	 * 
	 */
	void useTools();

	/**
	 * @brief Enters a workshop.
	 * 
	 * @param workshop The workshop to enter.
	 */
	void enter(Workshop *workshop);

	/**
	 * @brief Leaves the workshop the worker is currently in.
	 * 
	 */
	void leave(Workshop *workshop);

	/**
	 * @brief Makes the worker work in the workshop he is currently in.
	 * 
	 */
	void work();

private:

	/**
	 * @brief The set of tools the worker has.
	 * 
	 */
	ToolSet _tools;
	
	/**
	 * @brief The set of workshops the worker is in.
	 * 
	 */
	WorkshopSet _workshops;

	/** 
	 * @brief Removes a tool from the worker's toolset.
	 * 
	 * @param tool The tool to remove.
	 */
	void _removeTool(Tool *tool);
};

#endif // WORKER_HPP