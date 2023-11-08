#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <set>

class Room;
class Form;
class FormType;
class Course;
class Classroom;

class Person {

private:
	std::string _name;
	Room* _currentRoom;
public:
	Person(std::string name);
	Room* room() {return (_currentRoom);}
};

class Staff : public Person {

private:

public:
	void sign(Form* form);
};


class Student : public Person {

private:
	std::set<Course*> _subscribedCourse;

public:
	void attendClass(Classroom* classroom);
	void exitClass();
	void graduate(Course* course);
};

class Headmaster : public Staff {

private:
	std::set<Form*> _formToValidate;
	
public:
	void receiveForm(Form* form);
};

class Secretary : public Staff {

private:

public:
	Form* createForm(FormType formType);
	void archiveForm();
};

class Professor : public Staff {

private:
	Course* _currentCourse;

public:
	void assignCourse(Course* course);
	void doClass();
	void closeCourse();
};

#endif // PERSON_HPP