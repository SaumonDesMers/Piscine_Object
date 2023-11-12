#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <set>

#include "singleton.hpp"

class Professor;
class Student;

class Course {

public:

	Course(std::string name): _name(name) {
		(void)_numberOfClassToGraduate;
		(void)_maximumNumberOfStudent;
	}

	std::string const & name() {
		return this->_name;
	}

	void assign(Professor* professor) {
		this->_responsable = professor;
	}

	void subscribe(Student* student) {
		this->_students.insert(student);
	}

	void unsubscribe(Student* student) {
		this->_students.erase(student);
	}
	
private:
	std::string _name;
	Professor* _responsable;
	std::set<Student*> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;

};

class CourseList: public Singleton<CourseList>, public std::set<Course *> {};


#endif // COURSE_HPP