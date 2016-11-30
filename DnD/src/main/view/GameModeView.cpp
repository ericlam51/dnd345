#include "GameModeView.h"
#include <iostream>
#include <ctime>
#include <math.h>
#include <string>
#undef max
using namespace std;
//! method to display the main menu option
PlayModeController pmc;
void GameModeView::printMainMenu() {
	cout << "Hello, welcome to Dungeons and Dragons!" << endl;
	cout << "Select the mode:" << endl;
	cout << "1. Play mode" << endl;
	cout << "2. God mode" << endl;
	cout << "3. End program" << endl;
}

//! method to display the god mode menu option
void GameModeView::printGodModeMenu() {
	cout << "God mode selected." << endl;
	cout << "1. Map mode" << endl;
	cout << "2. Character mode" << endl;
	cout << "3. Item mode" << endl;
}
//! method to print the play menu option
void GameModeView::printPlayMenu() {
	cout << "Select which action you would like to perform" << endl;
	cout << "1. Move Up" << endl;
	cout << "2. Move Down" << endl;
	cout << "3. Move Left" << endl;
	cout << "4. Move Right" << endl;
	cout << "5. Show Player Inventory" << endl;
	cout << "6. Exit game" << endl;
}

void GameModeView::loadGame() {
	vector<string> mapFilenames = FileHelper::getFilenamesInDirectory(FileHelper::MAP_FILE_FOLDER);
	vector<string> fighterFilenames = FileHelper::getFilenamesInDirectory(FileHelper::FIGHTER_FILE_FOLDER);
	GameModeView::printLoadGame(mapFilenames, fighterFilenames);
}

string GameModeView::printLoadMap(vector<string> mapFilenames) {
	int mapInput = 0;
	while (mapInput - 1 < 0 || mapInput - 1 >= mapFilenames.size()) {
		cout << "Please select one of the following map files:" << endl;

		for (int i = 0; i < mapFilenames.size(); i++) {
			cout << i + 1 << ". " << mapFilenames[i] << endl;
		}

		cout << "Selection: ";

		cin >> mapInput;

		cin.clear(); //if cin fails because of wrong data type, clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer
	}

	return mapFilenames[mapInput - 1];
}

string GameModeView::printLoadFighter(vector<string> fighterFilenames) {
	int fighterInput = 0;
	while (fighterInput - 1 < 0 || fighterInput - 1 >= fighterFilenames.size()) {
		cout << "Please select one of the following fighter files:" << endl;

		for (int i = 0; i < fighterFilenames.size(); i++) {
			cout << i + 1 << ". " << fighterFilenames[i] << endl;
		}

		cout << "Selection: ";

		cin >> fighterInput;
		cin.clear(); //if cin fails because of wrong data type, clear error flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer
	}
	return fighterFilenames[fighterInput - 1];
}
void GameModeView::printLoadGame(vector<string> mapFilenames, vector<string> fighterFilenames) {
	string mapName = printLoadMap(mapFilenames);
	string fighterName = printLoadFighter(fighterFilenames);
	//PlayModeController pmc;
	pmc.loadGame(mapName, fighterName);
}

//! method to display the view, with a default parameter of 0 for main menu, 1 for game mode, 2 for god mode
void GameModeView::displayView(int gameMode) {
	do {
		int playing = false;
		//user input for the game mode menu
		while (gameMode != 1 && gameMode != 2 && gameMode != 3) {
			printMainMenu();
			cin >> gameMode;
			system("cls");
		}
		//go to the game mode
		if (gameMode == 1) {
			//PlayModeController pmc;
			int gameOption = 0;
			playing = true;
			loadGame();
			system("cls");
			while (playing) {
				while (gameOption < 1 || gameOption > 6) {
					system("cls");
					pmc.printMap();
					printPlayMenu();
					cin >> gameOption;
					system("cls");
				}
				switch (gameOption) {
					//Move up
				case 1:
					pmc.movePlayer('U');
					break;
					//Move down
				case 2:
					pmc.movePlayer('D');
					break;
					//Move Left
				case 3:
					pmc.movePlayer('L');
					break;
					//Move Right
				case 4:
					pmc.movePlayer('R');
					break;
					//Print equipped equipment
				case 5:
					pmc.printEquipment();
					break;
					//Exit the game
				case 6:
					playing = false;
					break;
				}
				gameOption = 0;

			}
		}
		//go to the god mode
		else if (gameMode == 2) {
			int godModeOption = 0;
			//Get input from the user for the god mode menu
			while (godModeOption != 1 && godModeOption != 2 && godModeOption != 3) {
				printGodModeMenu();
				cin >> godModeOption;
				system("cls");
			}
			//Redirect to the correct god mode menu
			if (godModeOption == 1) {
				GodmodeMapView::fileOptionsMenuView();
			}
			else if (godModeOption == 2) {
				GodmodeInteractableView::interactableFileSelectionView();
			}
			else if (godModeOption == 3) {
				GodmodeItemView::itemOptionSelection();
			}
		}
		else if (gameMode == 3) {
			break;
		}

		gameMode = -1;
		GodmodeMapController::instance()->resetController();
		GodmodeItemController::instance()->resetController();
		GodmodeActiveController::instance()->resetGodmodeActiveController();
		GodmodeChestController::instance()->resetGodmodeChestController();
		GodmodeFriendlyNpcController::instance()->resetGodmodeFriendlyNpcController();
	} while (true);

}

