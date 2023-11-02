#ifndef SALARIED_EMPLOYEE_HPP
#define SALARIED_EMPLOYEE_HPP

#include <iostream>

#include "employee.hpp"

class ContractEmployee: public Employee {

public:

	ContractEmployee(std::string name, int hourlyValue) : Employee(name, hourlyValue) {}

	void executeWorkday() {}

	int calculatePayroll() const {
		return this->hourlyValue * 7 * 5 * 4;
	}
};

class Apprentice: public Employee {

public:

	Apprentice(std::string name, int hourlyValue) : Employee(name, hourlyValue) {}

	void executeWorkday() {}

	int calculatePayroll() const {
		return this->hourlyValue * 7 * 5 * 4;
	}
};

#endif // SALARIED_EMPLOYEE_HPP