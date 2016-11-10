#include "../header/FriendlyNpc.h"
#include "../../Location.h"
#include <iostream>

using namespace std;

FriendlyNpc::FriendlyNpc() {}

FriendlyNpc::FriendlyNpc(string name, string description, string dialog) : Passive(name, description), dialog(dialog) {

}

void FriendlyNpc::print() {
	cout << "Name: " << name << endl
		<< "Description: " << description << endl
	    << "Dialog: " << dialog << endl;
}
void FriendlyNpc::interact() {
	cout << dialog;
}

