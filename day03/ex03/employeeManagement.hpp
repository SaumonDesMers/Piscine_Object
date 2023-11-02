#ifndef EMPLOYEE_MANAGEMENT_HPP
#define EMPLOYEE_MANAGEMENT_HPP

#include <iostream>
#include <set>

#include "employee.hpp"

class EmployeeManager {

public:

	void addEmployee(Employee *employee) {
		employees.insert(employee);
	}

	void removeEmployee(Employee *employee) {
		employees.erase(employee);
	}

	void executeWorkday() {
		for (std::set<Employee *>::iterator it = employees.begin(); it != employees.end(); ++it) {
			(*it)->executeWorkday();
		}
	}

	void calculatePayroll() {
		for (std::set<Employee *>::iterator it = employees.begin(); it != employees.end(); ++it) {
			std::cout << (*it)->name << " earned " << (*it)->calculatePayroll() << " this month." << std::endl;
		}
	}

private:

	std::set<Employee *> employees;
};

#endif // EMPLOYEE_MANAGEMENT_HPP