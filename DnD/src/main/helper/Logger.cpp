#include "Logger.h"

Logger* Logger::instance() 
{
	if (!l_instance) {
		l_instance = new Logger();
		l_instance->log = "";
		remove(l_instance->FILENAME);
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
	ofstream file(l_instance->FILENAME, ios::app);
	if (file.is_open())
	{
		file << str;
		file.close();
	}

}

void Logger::appendToNewLine(string str)
{
	l_instance->log += "\n" + str;
	ofstream file(l_instance->FILENAME, ios::app);
	if (file.is_open())
	{
		file << "\n" << str;
		file.close();
	}
}

Logger* Logger::l_instance = Logger::instance();