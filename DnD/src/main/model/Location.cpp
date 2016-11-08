#include "Location.h"
using namespace std;

Location::Location() {}

Location::Location(int newX, int newY) {
	x = newX;
	y = newY;
}

Location::~Location() {}

void Location::setXCoordinate(int newX) {
	x = newX;
}

void Location::setYCoordinate(int newY) {
	y = newY;
}

int Location::getXCoordinate() {
	return x;
}

int Location::getYCoordinate() {
	return y; 
}