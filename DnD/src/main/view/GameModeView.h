#pragma once
#include "map\godmode\GodmodeMapView.h"
#include "interactable\godmode\GodmodeInteractableView.h"
#include "item\godmode\GodmodeItemView.h"
#include "..\controller\PlayModeController.h"
class GameModeView
{
public:
	static void displayView(int gameMode = 0);
private:
	static void printMainMenu();
	static void printGodModeMenu();
	static void printPlayMenu();
};

