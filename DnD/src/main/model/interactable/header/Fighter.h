#pragma once
#include <iostream>
#include "Active.h"

using namespace std;


class Fighter : public Active
{
public:
	Fighter();
	Fighter(string name, string description, int level);
	void interact();
	void move(int x, int y);
};
