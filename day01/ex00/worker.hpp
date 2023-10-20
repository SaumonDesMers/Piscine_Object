#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <set>

#include "position.hpp"
#include "statistic.hpp"
#include "tool.hpp"
#include "workshop.hpp"

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
	~Worker();

	void addTool(Tool *tool);
	void removeTool(Tool *tool);

	ToolSet const & getTools() const;
	void useTools();

	void enter(Workshop *workshop);
	void leave(Workshop *workshop);

	void work();

private:

	ToolSet _tools;
	WorkshopSet _workshops;

};

#endif // WORKER_HPP