#include "GodmodeSettingsView.h"

void GodmodeSettingsView::displaySettings()
{
	cout << "Which components will be logged?" << endl;
	cout << "1. Game controller: " <<  (!Logger::instance()->gcLock? "true" : "false") << endl;
	cout << "2. Map: " << (!Logger::instance()->mapLock ? "true" : "false") << endl;
	cout << "3. Combat: " << (!Logger::instance()->combatLock ? "true" : "false") << endl;
	cout << "4. Dice: " << (!Logger::instance()->diceLock ? "true" : "false") << endl;

	string selection;

	do 
	{
		cout << "Selection (1 2 3 4): ";
		cin.ignore();
		getline(cin, selection);
	} while (!selection.find('1') && !selection.find('2') && !selection.find('3') && !selection.find('4'));
	GodmodeSettingsController::instance()->changeSettings(selection);

	cout << "Are you okay with these settings: \n\n";
	cout << "1. Game controller: " << (!Logger::instance()->gcLock ? "true" : "false") << endl;
	cout << "2. Map: " << (!Logger::instance()->mapLock ? "true" : "false") << endl;
	cout << "3. Combat: " << (!Logger::instance()->combatLock ? "true" : "false") << endl;
	cout << "4. Dice: " << (!Logger::instance()->diceLock ? "true" : "false") << endl;

	cin.clear();
	do 
	{
		cout << "Y/N: ";
		cin >> selection;
	} while (selection != "y" && selection !="Y" && selection != "n" && selection != "N");

	if (selection == "y" || selection == "Y") {
		system("cls");
		cout << "Settings successfully changed." << endl;
		return;
	}
	else {
		system("cls");
		displaySettings();
	}

}
