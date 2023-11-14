#include "professor.hpp"

void Professor::assignCourse(Course* course) {
	if (course == NULL)
		throw std::runtime_error("Course cannot be NULL");
	
	this->_currentCourse = course;
	this->_currentCourse->assign(this);
}

void Professor::teach() {
	if (this->_currentCourse) {
		std::cout << "Professor " << this->name() << " is doing class for course " << this->_currentCourse->name() << std::endl;
		this->_currentCourse->doClass();
	}
}