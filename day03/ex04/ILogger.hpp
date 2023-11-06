#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <iostream>
#include <fstream>
#include <ctime>

class ILogger {
	
public:

	virtual void write(std::string const & message) = 0;

};

class IFileLogger : virtual public ILogger {

public:

	IFileLogger(std::string const & filename) : _filename(filename) {
		this->_file.open(filename.c_str(), std::ios::out | std::ios::app);
	}

	~IFileLogger() {
		this->_file.close();
	}

	void setFilename(std::string const & filename) {
		this->_filename = filename;
		this->_file.close();
		this->_file.open(filename.c_str(), std::ios::out | std::ios::app);
	}

protected:

	std::string _filename;
	std::ofstream _file;

};

class IOstreamLogger : virtual public ILogger {

public:

	IOstreamLogger(std::ostream & stream) : _stream(&stream) {}

	void setStream(std::ostream & stream) {
		this->_stream = &stream;
	}

protected:

	std::ostream * _stream;
};

class ILoggerHeader: virtual public ILogger {

public:

	ILoggerHeader(std::string const & header = "", bool timestamp = false) : _header(header), _timestamp(timestamp) {}

	void setHeader(std::string const & header) {
		this->_header = header;
	}

	void setTimestamp(bool timestamp) {
		this->_timestamp = timestamp;
	}

protected:

	std::string _header;
	bool _timestamp;

	std::string _getTimestamp() {
		time_t now = time(0);
		tm *ltm = localtime(&now);
		char buffer[50];
		strftime(buffer, 50, "%Y-%m-%d %H:%M:%S", ltm);
		std::string timestamp(buffer);
		return timestamp;
	}

	std::string _addHeader(std::string const & message) {
		std::string completeMessage = "";
		if (this->_timestamp)
			completeMessage += this->_getTimestamp() + " ";
		if (this->_header != "")
			completeMessage += this->_header + " ";

		completeMessage += message;
		return completeMessage;
	}

};

#endif // ILOGGER_HPP