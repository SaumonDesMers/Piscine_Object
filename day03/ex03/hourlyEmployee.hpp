#ifndef HOURLY_EMPLOYEE_HPP
#define HOURLY_EMPLOYEE_HPP

#include <iostream>

#include "employee.hpp"

class TempWorker: public Employee {

public:

	TempWorker(std::string name, int hourlyValue) : Employee(name, hourlyValue), _hoursWorked(0) {}

	void executeWorkday() {
		this->_hoursWorked += 7;
	}

	int calculatePayroll() const {
		return this->_hoursWorked * this->hourlyValue;
	}

private:

	int _hoursWorked;
};

#endif // HOURLY_EMPLOYEE_HPP