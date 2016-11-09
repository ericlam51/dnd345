#include <iostream>
#include "../header/HostileNpc.h"

HostileNpc::HostileNpc(){

}

HostileNpc::HostileNpc(string name, string description, int level) : Active(name, description, level), size(size){

}

void HostileNpc::interact(){
	cout << "interact with hostile npc" << endl;
}

