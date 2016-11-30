#include "EntityCell.h"

IMPLEMENT_SERIAL(EntityCell, CObject, 1)

EntityCell::EntityCell()
{
	this->type = CellHelper::ENTITY_TYPE;
}

EntityCell::EntityCell(bool isFriendly) : EntityCell(){
	this->isFriendly = isFriendly;
}

EntityCell::~EntityCell()
{
}

void EntityCell::setEntity(Interactable* entity) {
	this->entity = entity;
}

void EntityCell::setType(char type) {
	this->type = type;
}

char EntityCell::printType() {
	if (isFriendly) {
		return 'N';
	}
	else {
		return 'X';
	}
}

bool EntityCell::interactable() {
	return true;
}

bool  EntityCell::walkable() {
	return true;
}

bool EntityCell::getIsFriendly() {
	return isFriendly;
}

void EntityCell::Serialize(CArchive& archive) {
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	// now do the stuff for our specific class
	if (archive.IsStoring()) {
		archive << posX << posY << type;
		entity->Serialize(archive);
	}
	else {
		archive >> posX >> posY >> type;
		entity = new HostileNpc();
		entity->Serialize(archive);
	}
}

void EntityCell::interact() {
	entity->interact();
}