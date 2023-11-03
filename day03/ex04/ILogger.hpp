#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include <string>

class ILogger {
	
public:

	virtual ~ILogger() {}
	virtual void write(std::string const & message) = 0;
};

#endif // ILOGGER_HPP