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
	
public:

	void receiveForm(Form* form) {
		this->_formToValidate.insert(form);
	}

	void workOnForm() {
		for (std::set<Form *>::iterator it = this->_formToValidate.begin(); it != this->_formToValidate.end(); it++) {
			// if form is complete
			(*it)->execute();
		}
	}

private:

	std::set<Form*> _formToValidate;

};

class Secretary : public Staff {

public:

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

	void assignCourse(Course* course);

	void doClass();

	void closeCourse();

private:

	Course* _currentCourse;

};