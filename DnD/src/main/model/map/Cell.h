#pragma once
class Cell
{
public:
	Cell();
	~Cell();
	virtual bool iterable();
	virtual bool walkable();
	virtual bool getType();
};

