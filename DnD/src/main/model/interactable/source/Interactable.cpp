#pragma once
#include <iostream>
#include "../../Location.h"
#include "../header/Interactable.h"

Interactable::Interactable() {}
Interactable::Interactable(string name, string description, Location location) :name(name), description(description), location(location) {

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