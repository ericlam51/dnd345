#pragma once
#include "Observer.h"
#include "../model/dice/Dice.h"
#include "Logger.h"

class DiceLogger : public Observer
{
public:
	DiceLogger();
	~DiceLogger();
	void Update();
	void display();
private:
	Dice* _diceSubject;
};

