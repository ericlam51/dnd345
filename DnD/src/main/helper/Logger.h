#pragma once
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Logger
{
	static Logger* l_instance;
public:
	static Logger * instance();
	string getLog();
	void appendToNewLine(string);
	void append(string);
	void saveLog();
private:
	string log;
};

