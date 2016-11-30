#include "CombatView.h"

CombatView* CombatView::instance() {
	if (!s_instance)
		s_instance = new CombatView();

	return s_instance;
	return new CombatView();
}

CombatView* CombatView::s_instance = CombatView::instance();