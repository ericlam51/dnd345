#include "DiceLogger.h"


DiceLogger::DiceLogger()
{
	Dice::instance()->Attach(this);
}


DiceLogger::~DiceLogger()
{
	Dice::instance()->Detach(this);
}


void DiceLogger::Update() {
	//display();
	Logger::instance()->appendToNewLine("Logging dice...");
	Logger::instance()->appendToNewLine(Dice::instance()->rollingMessage());
}

void DiceLogger::display() {
	Dice::instance()->displayRollingMessage();
}