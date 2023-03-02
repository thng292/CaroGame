#include "View.h"
#include "Language.h"
#include "Config.h"
#include "Navigate.h"

#define _TEST

#ifdef _TEST
	#include "Demo.h"
#endif


//DEMO PURPOSE ONLY
int main() {
	View::Setup();							// Setting up the screen
	Language::LoadLanguageFromFile("asset/language/vi.txt");
	Config::LoadUserSetting();
	// App start here
#ifdef _TEST
	return Demo();
#endif
	NavigationHost NavHost("", {

		});
}