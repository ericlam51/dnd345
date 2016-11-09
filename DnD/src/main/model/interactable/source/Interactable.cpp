#pragma once
#include <iostream>
#include "../../Location.h"
#include "../header/Interactable.h"

Interactable::Interactable() {}
Interactable::Interactable(string name, string description) :name(name), description(description){

}

string Interactable::getName() const{
	return name;
}
string Interactable::getDescription() const{
	return description;
}
Location Interactable::getLocation() const{
	return location;
}

void Interactable::setLocation(Location newlocation) {
	location = newlocation;
}