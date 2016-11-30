#pragma once
class CombatView
{
	// variable for the singleton 
	static CombatView * s_instance;
public:
	static CombatView* instance();
};

