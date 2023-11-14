#pragma once

#include "staff.hpp"

class Professor : public Staff {

public:

	Professor(std::string const & name): Staff(name), _currentCourse(NULL) {}

	void assignCourse(Course* course);

	void teach();

	void closeCourse() {
		this->_currentCourse = NULL;
	}

private:

	Course* _currentCourse;

};