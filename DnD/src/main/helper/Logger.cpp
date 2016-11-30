#include "Logger.h"

using namespace std;

Logger* Logger::instance() 
{
	if (!l_instance) {
		l_instance = new Logger();
		l_instance->log = "";
		l_instance->gcLock = false;
		l_instance->diceLock = false;
		l_instance->combatLock = false;
		l_instance->mapLock = false;
		remove(l_instance->FILENAME);
	}
	return l_instance;
}

string Logger::getLog()
{
	return l_instance->log;
}

void Logger::append(string str, string type = "MAP")
{
	if (!isTypeLocked(type)) 
	{
		l_instance->log += str;
		ofstream file(l_instance->FILENAME, ios::app);
		if (file.is_open())
		{
			file << str;
			file.close();
		}
	}
}

void Logger::appendToNewLine(string str, string type = "MAP")
{
	if (!isTypeLocked(type))
	{
		l_instance->log += "\n" + str;
		ofstream file(l_instance->FILENAME, ios::app);
		if (file.is_open())
		{
			file << "\n" << str;
			file.close();
		}
	}
}

bool Logger::isTypeLocked(string str) 
{
	if (str == LOGTYPES[0])
	{
		return gcLock;
	}
	else if (str == LOGTYPES[1])
	{
		return mapLock;
	}
	else if (str == LOGTYPES[2])
	{
		return combatLock;
	}
	else if (str == LOGTYPES[3])
	{
		return diceLock;
	}
	else
		return true;
}

Logger* Logger::l_instance = Logger::instance();