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
	void appendToNewLine(string, string);
	void append(string, string);
	bool isTypeLocked(string);
	bool gcLock;
	bool diceLock;
	bool combatLock;
	bool mapLock;
private:
	string log;
	const char* FILENAME = "gamelog.txt";
	const char* LOGTYPES[4] { "GAMECONTROLLER", "MAP", "COMBAT", "DICE" };
};

