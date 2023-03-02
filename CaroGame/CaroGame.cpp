#include "StartUp.h"
#include "Navigate.h"
//#define _TEST

#ifdef _TEST
	#include "Demo.h"
#endif


//DEMO PURPOSE ONLY
int main() {
#ifdef _TEST
	View::WriteToView(0, 0, Language::GetString(L"NEW_GAME_TITLE"));
	return Demo();
#endif
	NavigationHost NavHost("StartUpScreen", {
		{"StartUpScreen", StartUp::StartUpScreen},
		{"FirstTimeLanguageScreen", StartUp::FirstTimeLanguageScreen},
		{"FirstTimeMusicScreen", StartUp::FirstTimeMusicScreen}
		});
}