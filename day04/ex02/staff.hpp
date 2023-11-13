#pragma once

#include <iostream>
#include <typeinfo>

#include "person.hpp"
#include "singleton.hpp"
#include "form.hpp"
#include "course.hpp"

class Staff;

class StaffList: public Singleton<StaffList>, public std::set<Staff *> {};

class Staff : public Person {

public:

	Staff(std::string const & name): Person(name) {
		StaffList::getInstance()->insert(this);
	}

	void sign(Form* form) {
		form->execute();
	}

private:
};

class Headmaster : public Staff {
	
public:

	Headmaster(std::string const & name): Staff(name) {}

	void receiveForm(Form* form) {
		this->_formToValidate.insert(form);
	}

	void signForms() {
		for (std::set<Form *>::iterator it = this->_formToValidate.begin(); it != this->_formToValidate.end(); it++) {
			Form *form = *it;
			if (form->isComplete()) {
				std::cout << "Headmaster " << this->name() << " is signing form " << form->name() << std::endl;
				form->sign(this);
			} else {
				std::cout << "Headmaster " << this->name() << " is rejecting form " << form->name() << std::endl;
			}
		}
	}

private:

	std::set<Form*> _formToValidate;

};

class Secretary : public Staff {

public:

	Secretary(std::string const & name): Staff(name) {}

	Form* createForm(FormType formType) {
		switch (formType) {
		case CourseFinished:
			return new CourseFinishedForm();
		case NeedMoreClassRoom:
			return new NeedMoreClassRoomForm();
		case NeedCourseCreation:
			return new NeedCourseCreationForm();
		case SubscriptionToCourse:
			return new SubscriptionToCourseForm();
		}
		return NULL;
	}

	void archiveForm(Form *form) {
		delete form;
	}

private:

};

class Professor : public Staff {

public:

	Professor(std::string const & name): Staff(name) {}

	void assignCourse(Course* course) {
		this->_currentCourse = course;
	}

	void doClass() {
		if (this->_currentCourse) {
			std::cout << "Professor " << this->name() << " is doing class for course " << this->_currentCourse->name() << std::endl;
		}
	}

	void closeCourse() {
		this->_currentCourse = NULL;
	}

private:

	Course* _currentCourse;

};