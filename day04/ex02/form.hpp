#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

enum FormType {
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form {

private:
	FormType _formType;

public:
	Form(FormType formType): _formType(formType) {
		(void)_formType;
	}

	virtual void execute() = 0;
};

class CourseFinishedForm : public Form {

public:

	CourseFinishedForm(): Form(CourseFinished) {}

	void execute() {
		std::cout << "Execute CourseFinishedForm" << std::endl;
	}

private:

};

class NeedMoreClassRoomForm : public Form {

public:

	NeedMoreClassRoomForm(): Form(NeedMoreClassRoom) {}

	void execute() {
		std::cout << "Execute NeedMoreClassRoomForm" << std::endl;
	}

private:

};

class NeedCourseCreationForm : public Form {

public:

	NeedCourseCreationForm(): Form(NeedCourseCreation) {}

	void execute() {
		std::cout << "Execute NeedCourseCreationForm" << std::endl;
	}

private:

};

class SubscriptionToCourseForm : public Form {

public:

	SubscriptionToCourseForm(): Form(SubscriptionToCourse) {}

	void execute() {
		std::cout << "Execute SubscriptionToCourseForm" << std::endl;
	}

private:

};

#endif // FORM_HPP