#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>

class Employee {

public:

	std::string name;
	int hourlyValue;

	Employee(std::string name, int hourlyValue) : name(name), hourlyValue(hourlyValue) {}

	virtual void executeWorkday() = 0;

	virtual int calculatePayroll() const = 0;
};

#endif // EMPLOYEE_HPP