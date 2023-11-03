#include <iostream>

#include "employeeManagement.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main(void) {

	EmployeeManager manager;

	TempWorker tempWorker("John", 10);
	ContractEmployee contractEmployee("Jane", 1000);
	Apprentice apprentice("Jack", 100);

	manager.addEmployee(&tempWorker);
	manager.addEmployee(&contractEmployee);
	manager.addEmployee(&apprentice);

	manager.executeWorkday();

	tempWorker.mobilize(10);

	contractEmployee.takeDaysOff(5);

	apprentice.takeDaysOff(5);
	apprentice.attendSchool(10);

	manager.calculatePayroll();

	return 0;
}