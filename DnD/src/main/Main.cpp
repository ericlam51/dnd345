#include <iostream>
#include <ctime>
#include <math.h>
#include <string>
#include "view\map\godmode\GodmodeMapView.h"
#include "view\interactable\godmode\GodmodeInteractableView.h"
#include "view\item\godmode\GodmodeItemView.h"
#include "controller\PlayModeController.h"
using namespace std;

void printMainMenu() {
	cout << "HEllo, welcome to Dungeon and Dragon!" << endl;
	cout << "Select the mode:" << endl;
	cout << "1. Play mode" << endl;
	cout << "2. God mode" << endl;
}
void printGodModeMenu() {
	cout << "God mode selected." << endl;
	cout << "1. Map mode" << endl;
	cout << "2. Character mode" << endl;
	cout << "3. Item mode" << endl;
}
void printPlayMenu() {
	cout << "Select which action you would like to perform" << endl;
	cout << "1. Move Up" << endl;
	cout << "2. Move Down" << endl;
	cout << "3. Move Left" << endl;
	cout << "4. Move Right" << endl;
	cout << "5. Show Player Inventory" << endl;

}
int main()
{
	int gameMode = 0;
	int playing = false;
	//user input
	while (gameMode != 1 && gameMode != 2) {
		printMainMenu();
		cin >> gameMode;
		system("cls");
	}
	//user option
	if (gameMode == 1) {
		int gameOption = 0;
		playing = true;
		PlayModeController pmc;
		pmc.loadGame();
		system("cls");
		while (playing) {
			while (gameOption < 1 || gameOption > 6) {
				system("cls");
				pmc.printMap();
				printPlayMenu();
				cin >> gameOption;
				if (gameOption == -1) {
					playing = false;
					break;
				}
				system("cls");
			}
			switch (gameOption) {
				case 1: 
					pmc.movePlayer('U');
					break;
				case 2:
					pmc.movePlayer('D');
					break;
				case 3:
					pmc.movePlayer('L');
					break;
				case 4:
					pmc.movePlayer('R');
					break;
				case 5:
					pmc.printEquipment();
			}
			gameOption = 0;

		}
	
	
	
	
	}
	
	else if (gameMode == 2) {
		int godModeOption = 0;
		//user input
		while (godModeOption != 1 && godModeOption != 2 && godModeOption != 3) {
			printGodModeMenu();
			cin >> godModeOption;
			system("cls");
		}
		//user option
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
	
	
	return 0;
}
