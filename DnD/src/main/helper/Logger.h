#pragma once
#include <string>
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
private:
	string log;
	const char* FILENAME = "gamelog.txt";
};

