#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Headmaster;

enum FormType {
	CourseFinished = 0,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse
};

class Form {

protected:

	static std::string const _formName[];

	FormType _formType;
	bool _isSigned;

	void checkSignature() const {
		if (!this->_isSigned)
			throw std::runtime_error("Form not signed");
	}

public:

	Form(FormType formType): _formType(formType), _isSigned(false) {
		(void)_formType;
	}

	virtual ~Form() {}

	std::string const & name() const {
		return Form::_formName[this->_formType];
	}

	virtual void execute() = 0;

	virtual bool isComplete() const = 0;

	void sign(Headmaster *) {
		this->_isSigned = true;
	}

};

std::string const Form::_formName[] = {
	"CourseFinished",
	"NeedMoreClassRoom",
	"NeedCourseCreation",
	"SubscriptionToCourse"
};



class CourseFinishedForm : public Form {

public:

	CourseFinishedForm(): Form(CourseFinished) {}

	void execute() {
		this->checkSignature();
		std::cout << "Execute CourseFinishedForm" << std::endl;
	}

	bool isComplete() const {
		return this->_professorApproval;
	}

	void getProfessorApproval(Professor *) {
		std::cout << "CourseFinishedForm: Professor approval" << std::endl;
		this->_professorApproval = true;
	}

private:

	bool _professorApproval;

};


class NeedMoreClassRoomForm : public Form {

public:

	NeedMoreClassRoomForm(): Form(NeedMoreClassRoom) {}

	void execute() {
		this->checkSignature();
		std::cout << "Execute NeedMoreClassRoomForm" << std::endl;
	}

	bool isComplete() const {
		return true;
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

	bool isComplete() const {
		return true;
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

	bool isComplete() const {
		return true;
	}

private:

};

#endif // FORM_HPP