#pragma once

#include <iostream>

#include "person.hpp"
#include "singleton.hpp"
#include "form.hpp"

class Staff : public Person {

public:

	Staff(std::string const & name): Person(name) {}

	void sign(Form* form) {
		form->execute();
	}

private:
};

class StaffList: public Singleton<StaffList>, public std::set<Staff *> {};

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