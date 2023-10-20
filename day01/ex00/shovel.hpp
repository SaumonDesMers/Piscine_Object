#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include <iostream>

#include "worker.hpp"

#define LOG_FUNCTION std::cout << __PRETTY_FUNCTION__ << std::endl;

class Worker;

class Shovel
{
	friend class Worker;

public:

	Shovel();
	Shovel(int numberOfUses);
	~Shovel();

	int getNumberOfUses() const;
	void setNumberOfUses(int numberOfUses);

	void assign(Worker *worker);
	void unassign();

	void use();

private:

	int _numberOfUses;

	Worker *_worker;

};

#endif // SHOVEL_HPP