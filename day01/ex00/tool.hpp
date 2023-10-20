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
	~Tool();

	int getNumberOfUses() const;
	void setNumberOfUses(int numberOfUses);

	void assign(Worker *worker);
	void unassign();

	virtual void use() = 0;

protected:

	int _numberOfUses;

	Worker *_worker;

};

#endif // TOOL_HPP