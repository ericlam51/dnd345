#include "../header/FriendlyNpc.h"
#include "../../Location.h"
#include <iostream>

using namespace std;

FriendlyNpc::FriendlyNpc() {}

FriendlyNpc::FriendlyNpc(string name, string description, string dialog) : Passive(name, description), dialog(dialog) {

}

void FriendlyNpc::interact() {
	cout << dialog;
}

