#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <map>

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

class IStreamLogger : virtual public ILogger {

public:

	IStreamLogger(std::ostream & stream) : _stream(&stream) {}

	void setStream(std::ostream & stream) {
		this->_stream = &stream;
	}

protected:

	std::ostream * _stream;
};

class ILoggerHeader: virtual public ILogger {

protected:

	typedef std::string (ILoggerHeader::*addHeaderFct)();
	std::map<int, addHeaderFct> _addHeader;

	std::string _addHeaders(std::string const & message) {
		std::string completeMessage = "";

		for (std::map<int, addHeaderFct>::iterator it = this->_addHeader.begin(); it != this->_addHeader.end(); it++)
			completeMessage += (this->*(it->second))() + " ";

		completeMessage += message;
		return completeMessage;
	}
};

class ILoggerHeaderDate : public ILoggerHeader {
	
public:

	ILoggerHeaderDate() {
		this->_addHeader.insert(std::pair<int, addHeaderFct>(0, static_cast<addHeaderFct>(&ILoggerHeaderDate::_getTimestamp)));
	}

protected:

	std::string _getTimestamp() {
		time_t now = time(0);
		tm *ltm = localtime(&now);
		char buffer[50];
		strftime(buffer, 50, "[%Y-%m-%d %H:%M:%S]", ltm);
		std::string timestamp(buffer);
		return timestamp;
	}

};

class ILoggerHeaderConstant : public ILoggerHeader {

public:

	ILoggerHeaderConstant(std::string const & header = "") : _header(header) {
		this->_addHeader.insert(std::pair<int, addHeaderFct>(1, static_cast<addHeaderFct>(&ILoggerHeaderConstant::_getHeader)));
	}

	void setHeader(std::string const & header) {
		this->_header = header;
	}

protected:

	std::string _header;

private:

	std::string _getHeader() {
		return this->_header + ":";
	}

};

#endif // ILOGGER_HPP