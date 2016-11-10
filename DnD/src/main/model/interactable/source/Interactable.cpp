#include <iostream>
#include "../../Location.h"
#include "../header/Interactable.h"

IMPLEMENT_SERIAL(Interactable, CObject, 1)

Interactable::Interactable() {}
Interactable::Interactable(string name, string description) :name(name), description(description){

}

Interactable::~Interactable() {}

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

void Interactable::interact() {

}

void Interactable::Serialize(CArchive& archive) {}