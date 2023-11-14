#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <set>

#include "singleton.hpp"

class Person;
class Course;
class Form;

class Room {

public:

	Room(long long id): ID(id) {}

	long long name() {
		return this->ID;
	}

	bool canEnter(Person *) {
		return true;
	}

	void enter(Person * person) {
		this->_occupants.insert(person);
	}

	void exit(Person * person) {
		this->_occupants.erase(person);
	}
	
	void printOccupant() {
		std::cout << "Room " << this->ID << " occupants:" << std::endl;
		for (std::set<Person*>::iterator it = this->_occupants.begin(); it != this->_occupants.end(); it++) {
			std::cout << (*it)->name() << std::endl;
		}
	}

private:

	long long ID;
	std::set<Person*> _occupants;

};

class RoomList: public Singleton<RoomList>, public std::set<Room *> {};

class Classroom : public Room {

private:
	Course* _currentRoom;

public:
	Classroom();
	void assignCourse(Course* course);
};

class SecretarialOffice: public Room {

private:
	std::set<Form*> _archivedForms;

public:

};

class HeadmasterOffice : public Room {

private:

public:

};

class StaffRestRoom : public Room {

private:

public:

};

class Courtyard : public Room {

private:

public:

};

#endif // ROOM_HPP