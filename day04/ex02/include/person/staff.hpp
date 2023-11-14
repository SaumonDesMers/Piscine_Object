#pragma once

#include <iostream>
#include <typeinfo>

#include "person.hpp"
#include "singleton.hpp"
#include "form.hpp"
#include "course.hpp"

class Staff;
class Course;
class Form;

class StaffList: public Singleton<StaffList>, public std::set<Staff *> {};

class Staff : public Person {

public:

	Staff(std::string const & name): Person(name) {
		StaffList::getInstance()->insert(this);
	}

private:
};
