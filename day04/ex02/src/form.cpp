#include "form.hpp"
#include "staff.hpp"

//#####################################################################
//                                                                    #
//                                Form                                #
//                                                                    #
//#####################################################################

std::string const Form::_formName[] = {
	"CourseFinished",
	"NeedMoreClassRoom",
	"NeedCourseCreation",
	"SubscriptionToCourse"
};

//#####################################################################
//                                                                    #
//                         CourseFinishedForm                         #
//                                                                    #
//#####################################################################

void CourseFinishedForm::isComplete() const {
	if (this->_course == NULL)
		throw std::runtime_error("CourseFinishedForm invalid: course is NULL");
	if (this->_student == NULL)
		throw std::runtime_error("CourseFinishedForm invalid: student is NULL");
	if (!this->_course->canGraduate(this->_student))
		throw std::runtime_error("CourseFinishedForm invalid: student cannot graduate");
}