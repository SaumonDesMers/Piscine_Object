#pragma once

#include <iostream>

// #include "staff.hpp"
#include "course.hpp"

class Course;
class Student;

class Headmaster;

enum FormType {
	CourseFinished = 0,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form {

public:

	Form(FormType formType): _formType(formType), _isSigned(false) {}

	virtual ~Form() {}

	std::string const & name() const {
		return Form::_formName[this->_formType];
	}

	virtual void execute() = 0;

	void sign(Headmaster *) {
		this->isComplete();
		this->_isSigned = true;
	}

protected:

	static std::string const _formName[];

	FormType _formType;
	bool _isSigned;

	void checkSignature() const {
		if (!this->_isSigned)
			throw std::runtime_error("Form not signed");
	}

	virtual void isComplete() const {};

};


class CourseFinishedForm : public Form {

public:

	CourseFinishedForm(): Form(CourseFinished) {}

	void execute() {
		this->checkSignature();
		std::cout << "Execute CourseFinishedForm" << std::endl;
	}

	void isComplete() const;

	void setCourse(Course *course) {
		this->_course = course;
	}

	void setStudent(Student *student) {
		this->_student = student;
	}


private:

	Course *_course;
	Student *_student;

};


class NeedMoreClassRoomForm : public Form {

public:

	NeedMoreClassRoomForm(): Form(NeedMoreClassRoom) {}

	void execute() {
		this->checkSignature();
		std::cout << "Execute NeedMoreClassRoomForm" << std::endl;
	}

private:

};


class NeedCourseCreationForm : public Form {

public:

	NeedCourseCreationForm(): Form(NeedCourseCreation) {}

	void execute() {
		this->checkSignature();
		std::cout << "Execute NeedCourseCreationForm" << std::endl;
	}

private:

};


class SubscriptionToCourseForm : public Form {

public:

	SubscriptionToCourseForm(): Form(SubscriptionToCourse) {}

	void execute() {
		this->checkSignature();
		std::cout << "Execute SubscriptionToCourseForm" << std::endl;
	}

private:

};
