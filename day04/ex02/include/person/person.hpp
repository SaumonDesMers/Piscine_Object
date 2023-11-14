#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <set>

class Room;

class Person {

public:

	Person(std::string name): _name(name) {}

	std::string const & name() {
		return this->_name;
	}

	Room* room() {
		return _currentRoom;
	}

protected:

	std::string _name;

	Room* _currentRoom;

};


#endif // PERSON_HPP