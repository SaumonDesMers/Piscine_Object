#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <set>

#include "singleton.hpp"

class Person;
class Course;
class Form;

class Room {

private:
	long long ID;
	std::set<Person*> _occupants;

public:
	Room();
	bool canEnter(Person*);
	void enter(Person*);
	void exit(Person*);
	
	void printOccupant();
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