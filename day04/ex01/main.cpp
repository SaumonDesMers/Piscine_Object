#include <iostream>
#include <vector>

#include "student.hpp"
#include "course.hpp"
#include "room.hpp"
#include "staff.hpp"

template <class List, class Object, class ObjArg>
void testList(ObjArg const & arg) {

	std::cout << "\033[1;34m" << __PRETTY_FUNCTION__ << "\033[0m" << std::endl;

	List * list = List::getInstance();

	(void)arg;
	(void)list;

	list->insert(new Object(arg));

	for (typename List::iterator it = list->begin(); it != list->end(); it++) {
		Object * object = *it;
		std::cout << object->name() << std::endl;
	}

}

template<class List>
void cleanList() {

	List * list = List::getInstance();

	for (typename List::iterator it = list->begin(); it != list->end(); it++) {
		delete *it;
	}

	list->clear();
}

int main() {

	testList<StudentList, Student, std::string>("Bob");
	testList<StudentList, Student, std::string>("Sally");

	testList<StaffList, Staff, std::string>("Bob");
	testList<StaffList, Staff, std::string>("Sally");

	testList<CourseList, Course, std::string>("Bob");
	testList<CourseList, Course, std::string>("Sally");

	// testList<RoomList, Room, long long>(0);
	// testList<RoomList, Room, long long>(1);

	cleanList<StudentList>();
	cleanList<StaffList>();
	cleanList<CourseList>();
	// cleanList<RoomList>();

	return 0;
}