#include "GodmodeHostileNpcView.h"

void GodmodeHostileNpcView::newHostileNpctView() {

	string name, description;
	int level;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Enter monster's name: " << endl;
	cin >> name;

	cout << "Enter monster's description: " << endl;
	cin >> description;

	cout << "Enter monster's level: " << endl;
	cin >> level;

	GodmodeHostileNpcController::instance()->newHostileNpc(name, description, level);
}