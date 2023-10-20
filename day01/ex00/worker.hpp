#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>

#include "position.hpp"
#include "statistic.hpp"
#include "shovel.hpp"

class Shovel;

class Worker
{
	friend class Shovel;

public:

	Position position;
	Statistic statistic;

	Worker();

	void addShovel(Shovel *shovel);
	void removeShovel();

	void dig();
private:

	Shovel *_shovel;

};

#endif // WORKER_HPP