#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>

#include "ILogger.hpp"

class FileLogger : public IFileLogger {

public:

	FileLogger(std::string const & filename) : IFileLogger(filename) {}

	void write(std::string const & message) {
		this->_file << message << std::endl;
	}

};

class FileLoggerHeaderDate : public IFileLogger, public ILoggerHeaderDate {

public:

	FileLoggerHeaderDate(std::string const & filename) : IFileLogger(filename), ILoggerHeaderDate() {}

	void write(std::string const & message) {
		this->_file << this->_addHeaders(message) << std::endl;
	}

};

class FileLoggerHeaderConstant : public IFileLogger, public ILoggerHeaderConstant {

public:

	FileLoggerHeaderConstant(std::string const & filename, std::string const & header) : IFileLogger(filename), ILoggerHeaderConstant(header) {}

	void write(std::string const & message) {
		this->_file << this->_addHeaders(message) << std::endl;
	}

};

class StreamLogger : public IStreamLogger {

public:

	StreamLogger(std::ostream & stream) : IStreamLogger(stream) {}

	void write(std::string const & message) {
		*(this->_stream) << message << std::endl;
	}

};

class StreamLoggerHeaderDate : public IStreamLogger, public ILoggerHeaderDate {

public:

	StreamLoggerHeaderDate(std::ostream & stream) : IStreamLogger(stream) {}

	void write(std::string const & message) {
		*(this->_stream) << this->_addHeaders(message) << std::endl;
	}

};

class StreamLoggerHeaderConstant : public IStreamLogger, public ILoggerHeaderConstant {

public:

	StreamLoggerHeaderConstant(std::ostream & stream, std::string const & header = "") : IStreamLogger(stream), ILoggerHeaderConstant(header) {}

	void write(std::string const & message) {
		*(this->_stream) << this->_addHeaders(message) << std::endl;
	}

};

#endif // LOGGER_HPP