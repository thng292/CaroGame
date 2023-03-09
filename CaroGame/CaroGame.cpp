#include "StartUp.h"
#include "Navigate.h"
#include "MainMenu.h"
#include "Setting.h"
#include "GameScreen.h"
#include "GameView.h"
#include "InputBox.h"



//#define _TEST

//void ExitView(NavigationHost& NavHost) {
//	static short selectedOption = 1;										// User option
//	static const short maxOption = 2;										// Number of option
//	while (1) {																// Main while loop
//		View::DrawMenuCenter(L"Are you sure? ", {
//			{L"YES", L'Y'},
//			{L"NO :(", L'N'},
//			}, selectedOption);
//		auto tmp = InputHandle::Get();										// Get input from user
//		// Input Handle
//		// Normal Navigation
//		if (tmp == L"w" || tmp == L"W") {
//			selectedOption = (selectedOption - 1 + maxOption) % maxOption;	// Cycle effect
//		}
//		if (tmp == L"s" || tmp == L"S") {
//			selectedOption = (selectedOption + 1) % maxOption;				// Cycle effect
//		}
//		// Shortcut
//		if (tmp == L"Y") {
//			return NavHost.NavigateExit();									// Nho return
//		}
//		if (tmp == L"N") {
//			return NavHost.Back();											// Nho return
//		}
//		// Handle Select
//		if (tmp == L"\r") {
//			switch (selectedOption)
//			{
//			case 0:
//				return NavHost.NavigateExit();								// Nho return
//			case 1:
//				return NavHost.Back();										// Nho return
//			}
//		}
//	}
//}

//DEMO PURPOSE ONLY
//void TestView1(NavigationHost& NavHost) {
//	static short selectedOption = 0;										// User option
//	static const short maxOption = 3;										// Number of option
//	View::WriteToView(2, 2, L'\u2584', 0,
//		View::Color::LIGHT_RED, 
//		View::DEFAULT_HIGHLIGHT_COLOR, 
//		View::DEFAULT_HIGHLIGHT_TEXT_COLOR, 
//		View::Color::LIGHT_BLUE
//	);
//	View::WriteToView(3, 2, L'\u2588', 0, View::Color::BLACK);
//	View::DrawTextWrapped(0, 0, L"This is a very very long long text. This is a very very long long text. This is a very very long long text.", 2, 20);
//	NavHost.SetContext("TestContextValue", L"this is the context value");
//	while (1) {																// Main while loop
//		View::DrawMenuCenter(L"", {
//			{L"TestView2", L'2'},
//			{L"TestView3", L'3'},
//			{L"Exit", L'E'},
//			}, selectedOption);
//		auto tmp = InputHandle::Get();										// Get input from user
//		// Input Handle
//		// Normal Navigation
//		if (tmp == L"w" || tmp == L"W") {
//			selectedOption = (selectedOption - 1 + maxOption) % maxOption;	// Cycle effect
//		}
//		if (tmp == L"s" || tmp == L"S") {
//			selectedOption = (selectedOption + 1) % maxOption;				// Cycle effect
//		}
//		// Shortcut
//		if (tmp == L"2") {
//			return NavHost.Navigate("TestView2");							// Nho return
//		}
//		if (tmp == L"3") {
//			return NavHost.Navigate("TestView3");							// Nho return
//		}
//		if (tmp == L"e" || tmp == L"E") {
//			return NavHost.NavigateStack("ExitView");						// Nho return
//		}
//		// Handle Select
//		if (tmp == L"\r") {
//			switch (selectedOption)
//			{
//			case 0:
//				return NavHost.Navigate("TestView2");						// Nho return
//			case 1:
//				return NavHost.Navigate("TestView3");						// Nho return
//			case 2:
//				return NavHost.NavigateStack("ExitView");					// Nho return
//			}
//		}
//	}
//}

//DEMO PURPOSE ONLY
//void TestView2(NavigationHost& NavHost) {
//	View::WriteToView(20, 20, std::any_cast<const wchar_t*>(NavHost.GetFromContext("TestContextValue")), 0, true);
//	View::WriteToView(20, 21, L"Enter to go back", 0, true);
//	auto tmp = InputHandle::Get();
//	/*if (tmp == L"\r") {
//		return NavHost.Navigate("TestView3");
//	}*/
//	if (tmp == L"\r") {
//		return NavHost.Back();
//	}
//}
//
//void TestView3(NavigationHost& NavHost) {
//	
//}
//

//DEMO PURPOSE ONLY
int main() {
	View::Setup();							// Setting up the screen
	Language::LoadLanguageFromFile("asset/language/en.txt");
	NavigationHost NavHost("GameModeTypeView",
		{
			{"GameModeTypeView", GameView::GameModeTypeView},
			{"GameModeVersusView", GameView::GameModeVersusView},
			{"GameScreenView", GameView::GameScreenView},
			{"PlayerNameView", GameView::PlayerNameView},
			{"AIDifficultyView", GameView::AIDifficultyView},
			{"ReplayMenuView", GameView::ReplayMenuView},
			{"PlayAgainView", GameView::PlayAgainView},
			{"StartUpScreen", StartUp::StartUpScreen},
			{"FirstTimeLanguageScreen", StartUp::FirstTimeLanguageScreen},
			{"FirstTimeMusicScreen", StartUp::FirstTimeMusicScreen},
			{"FirstTimeSoundEffectScreen", StartUp::FirstTimeSoundEffectScreen},
			{"MainMenu", MainMenu::ScreenMainMenu},
			{"Setting", Setting::SettingScreen}
		}
	);
	/*std::vector<std::wstring> s = { L"Player 1's name:", L"Player 2's name:" };

	std::wstring a;
	bool maxReached = false;
	while (1) {
		InputBox::DrawInputBox(s, 1, a, maxReached, 6);
		auto tmp = InputHandle::Get();
		if (tmp == L"ESC") {
			a.pop_back();
			maxReached = false;
		}
		else {
			if (a.length() < 6) a += tmp;
			else maxReached = true;
		}
	}


	char c = _getch();*/

	// App start here

}