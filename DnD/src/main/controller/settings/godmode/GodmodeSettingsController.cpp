#include "GodmodeSettingsController.h"

GodmodeSettingsController* GodmodeSettingsController::instance()
{
	if (!s_instance)
	{
		s_instance = new GodmodeSettingsController();
	}
	return s_instance;
}

void GodmodeSettingsController::changeSettings(string input)
{
	if (input.find('1') != string::npos)
	{
		Logger::instance()->gcLock = !Logger::instance()->gcLock;
	}
	if (input.find('2') != string::npos)
	{
		Logger::instance()->mapLock = !Logger::instance()->mapLock;
	}	
	if (input.find('3') != string::npos)
	{
		Logger::instance()->combatLock = !Logger::instance()->combatLock;
	}	
	if (input.find('4') != string::npos)
	{

		Logger::instance()->diceLock = !Logger::instance()->diceLock;
	}
}

GodmodeSettingsController* GodmodeSettingsController::s_instance = GodmodeSettingsController::instance();