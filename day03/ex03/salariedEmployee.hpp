#ifndef SALARIED_EMPLOYEE_HPP
#define SALARIED_EMPLOYEE_HPP

#include <iostream>

#include "employee.hpp"

class ContractEmployee: public Employee {

public:

	ContractEmployee(std::string name, int hourlyValue) : Employee(name, hourlyValue), _hoursNotWorked(0) {}

	void executeWorkday() {
		std::cout << "Contract employee " << this->name << " is working." << std::endl;
	}

	int calculatePayroll() const {
		return this->hourlyValue * (7 * 5 * 4 - this->_hoursNotWorked);
	}

	void takeDaysOff(int days) {
		this->_hoursNotWorked += days * 7;
	}

private:

	int _hoursNotWorked;
};

class Apprentice: public Employee {

public:

	Apprentice(std::string name, int hourlyValue) : Employee(name, hourlyValue), _hoursNotWorked(0), _hoursInSchoolBeforeGoingToWork(0), _hoursInSchool(0) {}

	void executeWorkday() {
		int hoursInSchool = std::min(this->_hoursInSchoolBeforeGoingToWork, 7);
		if (hoursInSchool > 0) {
			std::cout << "Apprentice " << this->name << " is going to school for " << hoursInSchool << " hours." << std::endl;
			this->_hoursInSchoolBeforeGoingToWork -= hoursInSchool;
			this->_hoursInSchool += hoursInSchool;
		}
		if (hoursInSchool < 7) {
			std::cout << "Apprentice " << this->name << " is working for " << 7 - hoursInSchool << " hours." << std::endl;
		}
	}

	int calculatePayroll() const {
		return this->hourlyValue * (7 * 5 * 4 - this->_hoursNotWorked - (this->_hoursInSchool / 2));
	}

	void takeDaysOff(int days) {
		this->_hoursNotWorked += days * 7;
	}

	void attendSchool(int hours) {
		this->_hoursInSchoolBeforeGoingToWork += hours;
	}

private:

	int _hoursNotWorked;
	int _hoursInSchoolBeforeGoingToWork;
	int _hoursInSchool;
};

#endif // SALARIED_EMPLOYEE_HPP