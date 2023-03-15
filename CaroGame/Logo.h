#pragma once
#include "Navigate.h"
#include "InputHandle.h"
#include "View.h"
#include "Language.h"
#include "Utils.h"
#include "Config.h"
using namespace std;
namespace Logo {
	void Logo_Draw(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5);
	void Logo_Win(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5);
	void Logo_Lose(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5);
	void Draw(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5);
	void Lose(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5);
	void Win(NavigationHost& NavHost, int x, int y, View::Color a1, View::Color a2, View::Color a3, View::Color a4, View::Color a5);
	void AmongUs(int x, int y, View::Color mat, View::Color mau);    
	void Logo_Caro(int x, int y);                                      
	
}
