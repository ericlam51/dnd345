#include "EntityCell.h"

IMPLEMENT_SERIAL(EntityCell, CObject, 1)

EntityCell::EntityCell()
{
	type = CellHelper::ENTITY_TYPE;
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

bool EntityCell::interactable() {
	return true;
}

bool  EntityCell::walkable() {
	return true;
}

void EntityCell::Serialize(CArchive& archive) {
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	// now do the stuff for our specific class
	if (archive.IsStoring()) {
		archive << posX << posY << type;
	}
	else {
		archive >> posX >> posY >> type;
	}
}

void EntityCell::interact() {
	entity->interact();
}