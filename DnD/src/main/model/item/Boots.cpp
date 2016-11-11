#include "Boots.h"

IMPLEMENT_SERIAL(Boots, CObject, 1)

Boots::Boots(string name):Item(ItemTypes[BOOTS], name)
{
}


Boots::~Boots()
{
}

Boots::Boots()
{
}

void Boots::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	Item::Serialize(archive);

}
