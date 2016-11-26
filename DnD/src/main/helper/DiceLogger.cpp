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
	display();
}

void DiceLogger::display() {
	Dice::instance()->displayRollingMessage();
}