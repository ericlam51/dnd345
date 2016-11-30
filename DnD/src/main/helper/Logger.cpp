#include "Logger.h"

Logger* Logger::instance() 
{
	if (!l_instance) {
		l_instance = new Logger();
		l_instance->log = "";
	}
	return l_instance;
}

string Logger::getLog()
{
	return l_instance->log;
}

void Logger::append(string str)
{
	l_instance->log += str;
}

void Logger::appendToNewLine(string str)
{
	l_instance->log += "\n" + str;
}

Logger* Logger::l_instance = Logger::instance();