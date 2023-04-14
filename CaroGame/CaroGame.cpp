#include "About.h"
#include "GameEndView.h"
#include "GameScreen.h"
#include "GameScreenView.h"
#include "GameSelectionView.h"
#include "LoadScreen.h"
#include "MainMenu.h"
#include "Navigate.h"
#include "ReplayLoad.h"
#include "ReplaySave.h"
#include "ReplayScreenView.h"
#include "SaveScreen.h"
#include "Setting.h"
#include "StartUp.h"
#include "Theme.h"
#include "Tutorial.h"

int main()
{
#if _DEBUG
    Language::LoadLanguageFromFile("asset/language/en.txt");
    View::Setup();
    // Theme::LoadTheme("themes/TestTheme");
#endif
    NavigationHost(
#if _DEBUG
        "StartUpScreen",
#else
        "StartUpScreen",
#endif
        {
            {"About",                      About::AboutScreen                   },
            {"GameEndView",                GameEndView::GameEndView             },
            {"GameScreenView",             GameScreenView::GameScreenView       },
            {"AIDifficultyView",           GameSelectionView::AIDifficultyView  },
            {"AreYouSureView",             GameSelectionView::AreYouSureView    },
            {"AvatarSelectView",           GameSelectionView::AvatarSelectView  },
            {"GameModeTypeView",           GameSelectionView::GameModeTypeView  },
            {"GameModeVersusView",         GameSelectionView::GameModeVersusView},
            {"PauseMenuView",              GameSelectionView::PauseMenuView     },
            {"PlayerNameView",             GameSelectionView::PlayerNameView    },
            {"PlayAgainView",              GameSelectionView::PlayAgainView     },
            {"ReplayMenuView",             GameSelectionView::ReplayMenuView    },
            {"RushTimeView",               GameSelectionView::RushTimeView      },
            {"LoadScreen",                 LoadScreen::LoadSceen                },
            {"LoadFailed",                 LoadScreen::LoadFailed               },
            {"EmptyLoad",                  LoadScreen::EmptyLoad                },
            {"MainMenu",                   MainMenu::ScreenMainMenu             },
            {"ReplayLoad",                 ReplayLoad::ReplayLoad               },
            {"ReplaySave",                 ReplaySave::ReplaySave               },
            {"ReplayScreenView",           ReplayScreenView::ReplayScreenView   },
            {"SaveScreen",                 SaveScreen::SaveScreen               },
            {"SaveSuccess",                SaveScreen::SaveSuccess              },
            {"SaveFailed",                 SaveScreen::SaveFailed               },
            {"SettingApplied",             Setting::ApplySuccess                },
            {"SettingsAppliedFailed",      Setting::ApplyFailed                 },
            {"Setting",                    Setting::SettingScreen               },
            {"ExitScreen",                 StartUp::ExitScreen                  },
            {"FirstTimeLanguageScreen",    StartUp::FirstTimeLanguageScreen     },
            {"FirstTimeMusicScreen",       StartUp::FirstTimeMusicScreen        },
            {"FirstTimeSoundEffectScreen", StartUp::FirstTimeSoundEffectScreen  },
            {"FirstTimeTutorialScreen",    StartUp::FirstTimeTutorialScreen     },
            {"StartUpScreen",              StartUp::StartUpScreen               },
            {"ReplayScreenView",           ReplayScreenView::ReplayScreenView   },
            {"Tutorial",                   Tutorial::TutorialScreen             },
    }
    );
}