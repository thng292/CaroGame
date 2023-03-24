﻿#include "GameScreen.h"
#include "GameView.h"
#include "LoadScreen.h"
#include "MainMenu.h"
#include "Navigate.h"
#include "ReplayLoad.h"
#include "ReplaySave.h"
#include "SaveScreen.h"
#include "Setting.h"
#include "StartUp.h"

int main()
{

#if _DEBUG
    Language::LoadLanguageFromFile("asset/language/en.txt");
    View::Setup();
#endif
    NavigationHost NavHost(
#if _DEBUG
        "GameModeTypeView",
#else
        "StartUpScreen",
#endif
        {
            {"GameModeTypeView",           GameView::GameModeTypeView         },
            {"GameModeVersusView",         GameView::GameModeVersusView       },
            {"GameScreenView",             GameView::GameScreenView           },
            {"PlayerNameView",             GameView::PlayerNameView           },
            {"AIDifficultyView",           GameView::AIDifficultyView         },
            {"ReplayMenuView",             GameView::ReplayMenuView           },
            {"PlayAgainView",              GameView::PlayAgainView            },
            {"LoadScreen",                 LoadScreen::LoadSceen              },
            {"LoadFailed",                 LoadScreen::LoadFailed             },
            {"EmptyLoad",                  LoadScreen::EmptyLoad              },
            {"MainMenu",                   MainMenu::ScreenMainMenu           },
            {"ReplayLoad",                 ReplayLoad::ReplayLoad             },
            {"ReplaySave",                 ReplaySave::ReplaySave             },
            {"SaveScreen",                 SaveScreen::SaveScreen             },
            {"SaveSuccess",                SaveScreen::SaveSuccess            },
            {"SaveFailed",                 SaveScreen::SaveFailed             },
            {"Setting",                    Setting::SettingScreen             },
            {"StartUpScreen",              StartUp::StartUpScreen             },
            {"FirstTimeLanguageScreen",    StartUp::FirstTimeLanguageScreen   },
            {"FirstTimeMusicScreen",       StartUp::FirstTimeMusicScreen      },
            {"FirstTimeSoundEffectScreen", StartUp::FirstTimeSoundEffectScreen},
            {"RushTimeView",               GameView::RushTimeView             },
            {"PauseMenuView", GameView::PauseMenuView}
    }
    );
}