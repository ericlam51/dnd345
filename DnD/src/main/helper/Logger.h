#pragma once
#include <string>

using namespace std;

class Logger
{
	static Logger* l_instance;
public:
	static Logger * instance();
	string getLog();
	void appendToNewLine(string);
	void append(string);
private:
	string log;
};

