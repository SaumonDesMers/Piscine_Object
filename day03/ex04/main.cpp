#include <iostream>
#include <vector>

#include "ILogger.hpp"
#include "logger.hpp"

void test(ILogger *logger) {
	logger->write("This is a test");
}

int main() {

	std::vector<ILogger *> loggers;

	FileLogger fileLogger("log.txt");
	fileLogger.write("This is the file logger writing to log.txt");
	loggers.push_back(&fileLogger);

	FileLoggerHeaderDate fileLoggerHeaderDate("log.txt");
	fileLoggerHeaderDate.write("This is the file logger with header date writing to log.txt");
	loggers.push_back(&fileLoggerHeaderDate);

	FileLoggerHeaderConstant fileLoggerHeaderConstant("log.txt", "HEADER");
	fileLoggerHeaderConstant.write("This is the file logger with header constant writing to log.txt");
	loggers.push_back(&fileLoggerHeaderConstant);

	StreamLogger ostreamLogger(std::cout);
	ostreamLogger.write("This is the ostream logger writing to std::cout");
	loggers.push_back(&ostreamLogger);

	StreamLoggerHeaderDate ostreamLoggerHeaderDate(std::cout);
	ostreamLoggerHeaderDate.write("This is the ostream logger with header date writing to std::cout");
	loggers.push_back(&ostreamLoggerHeaderDate);

	StreamLoggerHeaderConstant ostreamLoggerHeaderConstant(std::cout, "HEADER");
	ostreamLoggerHeaderConstant.write("This is the ostream logger with header constant writing to std::cout");
	loggers.push_back(&ostreamLoggerHeaderConstant);

	for (std::vector<ILogger *>::iterator it = loggers.begin(); it != loggers.end(); it++) {
		test(*it);
	}


	return 0;
}