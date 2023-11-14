#include <iostream>
#include <vector>

#include "student.hpp"
#include "course.hpp"
#include "room.hpp"
#include "staff.hpp"
#include "headmaster.hpp"
#include "secretary.hpp"
#include "professor.hpp"

int main() {

	Headmaster headmaster("John");
	Secretary secretary("Bob");
	Professor professor("Jack");
	Student student("Alice");
	Course course("C++", 1, 10);

	Form *form = secretary.createForm(CourseFinished);

	try {

		CourseFinishedForm &courseFinishedForm = dynamic_cast<CourseFinishedForm &>(*form);

		course.subscribe(&student);
		professor.assignCourse(&course);
		professor.teach();

		headmaster.receiveForm(&courseFinishedForm);
		courseFinishedForm.setCourse(&course);
		courseFinishedForm.setStudent(&student);

		headmaster.signForms();

		courseFinishedForm.execute();

	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	secretary.archiveForm(form);

	return 0;
}