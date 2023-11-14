#pragma once

#include "staff.hpp"

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
