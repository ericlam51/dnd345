#pragma once
#include "../../helper/CellHelper.cpp"

class Cell
{
protected:
	char type;
	int posX;
	int posY;

public:
	Cell();
	~Cell();
	virtual bool interactable() = 0;
	virtual bool walkable() = 0;
	virtual inline char getType() = 0;
	 int getPosX();
	 int getPosY();
	 void setPosX(int x);
	 void setPosY(int y);
};

