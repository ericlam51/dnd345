#pragma once

#include <iostream>
#include <ctime>
#include <math.h>
#include <string>
#include "view\GameModeView.h"
#include "helper\FileHelper.h"

using namespace std;

int main(){

	srand((unsigned)time(NULL));
	GameModeView gmv;
	gmv.displayView();
	
	return 0;
}
