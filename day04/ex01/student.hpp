#pragma once

#include <iostream>
#include <set>

#include "singleton.hpp"
#include "person.hpp"

class Classroom;
class Course;

class Student : public Person {

public:

	Student(std::string name): Person(name) {}

	void attendClass(Classroom* classroom);

	void exitClass();

	void graduate(Course* course);

private:

	std::set<Course*> _subscribedCourse;

};

class StudentList: public Singleton<StudentList>, public std::set<Student *> {};