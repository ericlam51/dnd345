#include <iostream>
#include "../header/HostileNpc.h"

IMPLEMENT_SERIAL(HostileNpc, CObject, 1)

HostileNpc::HostileNpc(){}

HostileNpc::HostileNpc(string name, string description, int level) : Active(name, description, level), size(size){

}

HostileNpc::~HostileNpc() {}

void HostileNpc::interact(){
	cout << "interact with hostile npc" << endl;
}

void HostileNpc::Serialize(CArchive& archive) {
	CObject::Serialize(archive);

	if (archive.IsStoring()) {
		CString cName(getName().c_str());
		CString cDescription(getDescription().c_str());
		archive << cName << cDescription << getLevel()
			<< getStrength() << getDexterity() << getConstitution()
			<< getIntelligence() << getWisdom() << getCharisma(); //TODO serialize item
	}
}