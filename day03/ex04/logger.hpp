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

class FileLoggerHeader : public IFileLogger, public ILoggerHeader {

public:

	FileLoggerHeader(std::string const & filename, std::string const & header = "", bool timestamp = false) : IFileLogger(filename), ILoggerHeader(header, timestamp) {}

	void write(std::string const & message) {
		this->_file << this->_addHeader(message) << std::endl;
	}

};

class OstreamLogger : public IOstreamLogger {

public:

	OstreamLogger(std::ostream & stream) : IOstreamLogger(stream) {}

	void write(std::string const & message) {
		*(this->_stream) << message << std::endl;
	}

};

class OstreamLoggerHeader : public IOstreamLogger, public ILoggerHeader {

public:

	OstreamLoggerHeader(std::ostream & stream, std::string const & header = "", bool timestamp = false) : IOstreamLogger(stream), ILoggerHeader(header, timestamp) {}

	void write(std::string const & message) {
		*(this->_stream) << this->_addHeader(message) << std::endl;
	}

};

#endif // LOGGER_HPP