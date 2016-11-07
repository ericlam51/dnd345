#pragma once

using namespace std;

class Location
{
public:
	Location();
	Location(int x, int y);
	~Location();
	void setXCoordinate(int x);
	void setYCoordinate(int y);
	int getXCoordinate();
	int getYCoordinate();
private:
	int x;
	int y;
};
