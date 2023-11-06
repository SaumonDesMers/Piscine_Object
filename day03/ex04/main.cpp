#include <iostream>

#include "ILogger.hpp"
#include "logger.hpp"

void test(ILogger &logger) {
	logger.write("This is a test");
}

int main() {

	FileLogger fileLogger("log.txt");
	fileLogger.write("This is the file logger writing to log.txt");

	OstreamLogger ostreamLogger(std::cout);
	ostreamLogger.write("This is the ostream logger writing to std::cout");

	FileLoggerHeader fileLoggerHeader("log.txt", "HEADER", true);
	fileLoggerHeader.write("This is the file logger header writing to log.txt");

	OstreamLoggerHeader ostreamLoggerHeader(std::cout, "HEADER");
	ostreamLoggerHeader.write("This is the ostream logger header writing to std::cout");

	test(fileLogger);
	test(ostreamLogger);
	test(fileLoggerHeader);
	test(ostreamLoggerHeader);

	return 0;
}