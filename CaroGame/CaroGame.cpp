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
	NavigationHost NavHost("MainMenu",
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
			{"Load",						LoadScreen::Load					}
		}
	);
	
}