#pragma once
#include <iostream>
#include "../header/HostileNpc.h"

HostileNpc::HostileNpc(){

}

HostileNpc::HostileNpc(string name, string description, Location location, int level) : Active(name, description, location, level), size(size){

}

void HostileNpc::interact(){
	cout << "interact with hostile npc" << endl;
}

