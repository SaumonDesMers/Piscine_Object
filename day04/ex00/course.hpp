#ifndef COURSE_HPP
#define COURSE_HPP

#include <iostream>
#include <set>

class Professor;
class Student;

class Course {
	
private:
	std::string _name;
	Professor* _responsable;
	std::set<Student*> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
public:
	Course(std::string name);
	void assign(Professor* professor);
	void subscribe(Student* student);
};


#endif // COURSE_HPP