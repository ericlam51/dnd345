#pragma once
#include "map\godmode\GodmodeMapView.h"
#include "interactable\godmode\GodmodeInteractableView.h"
#include "item\godmode\GodmodeItemView.h"
#include "..\controller\PlayModeController.h"
#include "..\helper\Logger.h"
#include "settings\godmode\GodmodeSettingsView.h"

class GameModeView
{
public:
	static void displayView(int gameMode = 0);
	static void endGame();
private:
	static void printMainMenu();
	static void printGodModeMenu();
	static void printPlayMenu();
	static void loadGame();
	static void printLoadGame(vector<string>, vector<string>);
	static string printLoadFighter(vector<string>);
	static string printLoadMap(vector<string>);
};

