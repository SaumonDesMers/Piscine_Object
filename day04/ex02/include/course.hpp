#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <map>

#include "singleton.hpp"
#include "staff.hpp"

class Professor;
class Student;

class Course {

public:

	Course(std::string name, int numberOfClassToGraduate, int maximumNumberOfStudent):
		_name(name), _responsable(NULL), _numberOfClassToGraduate(numberOfClassToGraduate), _maximumNumberOfStudent(maximumNumberOfStudent) {
	}

	std::string const & name() {
		return this->_name;
	}

	void assign(Professor* professor) {
		this->_responsable = professor;
	}

	void subscribe(Student* student) {
		if (this->_students.size() >= this->_maximumNumberOfStudent)
			throw std::runtime_error("Course is full");
		this->_students[student] = 0;
	}

	void unsubscribe(Student* student) {
		this->_students.erase(student);
	}

	void doClass() {
		for (std::map<Student*, int>::iterator it = this->_students.begin(); it != this->_students.end(); it++) {
			it->second++;
		}
	}

	int numberOfClassToGraduate() {
		return this->_numberOfClassToGraduate;
	}

	bool isFull() {
		return this->_students.size() >= this->_maximumNumberOfStudent;
	}
	
	bool canGraduate(Student * student) {
		if (this->_students.find(student) == this->_students.end())
			throw std::runtime_error("Student not subscribed to this course");
		return this->_students[student] >= this->_numberOfClassToGraduate;
	}

private:

	std::string _name;
	Professor* _responsable;
	std::map<Student*, int> _students;
	int _numberOfClassToGraduate;
	size_t _maximumNumberOfStudent;

};

class CourseList: public Singleton<CourseList>, public std::set<Course *> {};


#endif // COURSE_HPP