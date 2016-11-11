#include "Ring.h"

IMPLEMENT_SERIAL(Ring, CObject, 1)

Ring::Ring(string name):Item(ItemTypes[RING], name)
{
}


Ring::~Ring()
{
}

Ring::Ring() 
{
}

void Ring::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	Item::Serialize(archive);

}
