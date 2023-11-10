#pragma once

#include <iostream>

template<class T>
class Singleton {

public:

	static T * getInstance();

protected:

	static T *_instance;

	Singleton() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

};

template<class T>
T * Singleton<T>::_instance = NULL;

template<class T>
T * Singleton<T>::getInstance() {
	if (_instance == NULL) {
		_instance = new T();
	}
	return _instance;
}