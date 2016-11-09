#pragma once

#include "../../../helper/ViewHelper.h"
#include "../../../controller/interactable/godmode/GodmodeFighterController.h"
#include "../../../model/interactable/header/ActiveBuilder.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeFighterView {
public:
	static void newfighterView();

private:
	void fighterStatsView();
}
