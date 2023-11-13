#include <iostream>
#include <vector>

#include "student.hpp"
#include "course.hpp"
#include "room.hpp"
#include "staff.hpp"

int main() {

	Headmaster headmaster("John");
	Secretary secretary("Bob");
	Professor professor("Alice");

	Form *form = secretary.createForm(CourseFinished);

	try {

		CourseFinishedForm &courseFinishedForm = dynamic_cast<CourseFinishedForm &>(*form);

		// courseFinishedForm.getProfessorApproval(&professor);

		headmaster.receiveForm(&courseFinishedForm);

		headmaster.signForms();

		courseFinishedForm.execute();

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	secretary.archiveForm(form);

	return 0;
}