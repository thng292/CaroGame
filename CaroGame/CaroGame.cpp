#include "StartUp.h"
#include "Navigate.h"
#include "MainMenu.h"
#include "Setting.h"
#include "GameScreen.h"
#include "GameView.h"
#include "LoadScreen.h"

int main() {
	View::Setup();							// Setting up the screen
	Language::LoadLanguageFromFile("asset/language/en.txt");
	/*while (true)
	{
		auto tmp = _getwch();
		std::wcout << tmp << ' ';
	}*/
	/*std::wstring inpTxt = L"Thong";
	while (true)
	{
		View::Input(10, 10, L"Your Name", inpTxt, true, [&inpTxt](auto newTxt) {
			inpTxt = newTxt;
		});
	}*/
 	NavigationHost NavHost("GameModeTypeView",
		{
			{"GameModeTypeView",			GameView::GameModeTypeView			},
			{"GameModeVersusView",			GameView::GameModeVersusView		},
			{"GameScreenView",				GameView::GameScreenView			},
			{"PlayerNameView",				GameView::PlayerNameView			},
			{"AIDifficultyView",			GameView::AIDifficultyView			},
			{"ReplayMenuView",				GameView::ReplayMenuView			},
			{"PlayAgainView",				GameView::PlayAgainView				},
			{"StartUpScreen",				StartUp::StartUpScreen				},
			{"FirstTimeLanguageScreen",		StartUp::FirstTimeLanguageScreen	},
			{"FirstTimeMusicScreen",		StartUp::FirstTimeMusicScreen		},
			{"FirstTimeSoundEffectScreen",	StartUp::FirstTimeSoundEffectScreen	},
			{"MainMenu",					MainMenu::ScreenMainMenu			},
			{"Setting",						Setting::SettingScreen				},
			{"Load",						LoadScreen::Load					},
			{"ReplaySaveView",					GameView::ReplaySaveView		},
		}
	);
	
}