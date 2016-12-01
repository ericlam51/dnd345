#pragma once
#include <string>
#include "../../../helper/Logger.h"

using namespace std;

class GodmodeSettingsController
{
	static GodmodeSettingsController* s_instance;
public:
	static GodmodeSettingsController* instance();
	void changeSettings(string);
};

