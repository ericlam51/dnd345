#include "Shield.h"

IMPLEMENT_SERIAL(Shield, CObject, 1)

Shield::Shield(string name):Item(ItemTypes[SHIELD], name)
{
}


Shield::~Shield()
{
}

Shield::Shield()
{
}

void Shield::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	Item::Serialize(archive);

	// now do the stuff for our specific class
	//if (archive.IsStoring())
	//	archive << m_name << m_number;
	//else
	//	archive >> m_name >> m_number;
}
