#pragma once
#include "Navigate.h"
#include "InputHandle.h"
#include "View.h"
#include "Language.h"
using namespace std;
namespace MainMenu {
	void Avatar(int x, int y, View::Color mat, View::Color mau);       // Paint Among us
	void Logo(int x, int y);                                        // Paint Logo
	void ScreenMainMenu(NavigationHost& NavHost);                   // Paint Main Menu
}
