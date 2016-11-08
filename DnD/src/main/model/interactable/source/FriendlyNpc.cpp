#include "../header/FriendlyNpc.h"
#include "../../Location.h"
#include <iostream>

using namespace std;

FriendlyNpc::FriendlyNpc() {}

FriendlyNpc::FriendlyNpc(string name, string description, Location location, string dialog) : Passive(name, description, location), dialog(dialog) {

}

void FriendlyNpc::interact() {
	cout << dialog;
}

