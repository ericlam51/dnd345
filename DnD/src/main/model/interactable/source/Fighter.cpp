#include <iostream>
#include <ctime>
#include <math.h>
#include "../header/Fighter.h"
#include <string>

using namespace std;

Fighter::Fighter() {}
Fighter::Fighter(string name, string description, int level) : Active(name, description, level){
}

void Fighter::move(int x, int y) {
	Interactable::location.setXCoordinate(x);
	Interactable::location.setYCoordinate(y);
}
void Fighter::interact() {
	cout << "interact with fighter" << endl;
}