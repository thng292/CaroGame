#include "MainMenu.h"

void MainMenu::ScreenMainMenu(NavigationHost& NavHost)
{
    NavHost.SetContext(Constants::CURRENT_BGM, Audio::Sound::MenuBGM);
    if (Config::GetConfig(Config::BGMusic) == Config::Value_True) {
        if (BackgroundAudioService::GetCurrentSong() != Audio::Sound::MenuBGM) {
            BackgroundAudioService::ChangeSong(Audio::Sound::MenuBGM);
            BackgroundAudioService::Play(true, true);
        }
    }

    static short selectedOption = 0;   // User option
    static const short maxOption = 7;  // Number of option
                                       // Vi tri bat dau ve
    Common::DrawHintsLess();
    Caro(32, 1);
    Logo_Deadpool(3, 5);
    Logo_Captain(79 + 4, 5);
    View::WriteToView(119 - Constants::version.size(), 0, Constants::version);

    std::vector<View::Option> options = {
        {Language::GetString(L"NEW_GAME_TITLE"),
         Language::GetString(L"NEW_GAME_SHORTCUT")[0]},
        {Language::GetString(L"LOAD_TITLE"),
         Language::GetString(L"LOAD_SHORTCUT")[0]    },
        {Language::GetString(L"REPLAY_TITLE"),
         Language::GetString(L"REPLAY_SHORTCUT")[0]  },
        {Language::GetString(L"SETTINGS_TITLE"),
         Language::GetString(L"SETTINGS_SHORTCUT")[0]},
        {Language::GetString(L"TUTORIAL_TITLE"),
         Language::GetString(L"TUTORIAL_SHORTCUT")[0]},
        {Language::GetString(L"ABOUT_TITLE"),
         Language::GetString(L"ABOUT_SHORTCUT")[0]   },
        {Language::GetString(L"EXIT_TITLE"),
         Language::GetString(L"EXIT_SHORTCUT")[0]    },
    };
    auto& soundEffect = Config::GetConfig(L"SoundEffect");
    View::DrawMenuPrevState menuPrevState;

    while (1) {  // Main while loop
        View::DrawMenu(menuPrevState, 50, 13, L"", options, selectedOption);
        auto tmp = InputHandle::Get();  // Get input from user
        if (soundEffect == Config::Value_True) {
            if (tmp == L"\r") {
                Utils::PlaySpecialKeySound();
            } else {
                Utils::PlayKeyPressSound();
            }
        }
        // Input Handle
        // Normal Navigation
        if (Utils::keyMeanUp(tmp)) {
            selectedOption =
                Utils::modCycle(selectedOption - 1, options.size());
        }
        if (Utils::keyMeanDown(tmp)) {
            selectedOption =
                Utils::modCycle(selectedOption + 1, options.size());
        }

        // TODO ???????????????????
        // Shortcut
        if (tmp == Language::GetString(L"NEW_GAME_SHORTCUT")) {
            return NavHost.Navigate("GameModeTypeView");  // Nho return
        }
        if (tmp == Language::GetString(L"LOAD_SHORTCUT")) {
            return NavHost.Navigate("LoadScreen");  // Nho return
        }
        if (tmp == Language::GetString(L"REPLAY_SHORTCUT")) {
            return NavHost.Navigate("ReplayLoad");  // Nho return
        }
        if (tmp == Language::GetString(L"SETTINGS_SHORTCUT")) {
            return NavHost.Navigate("Setting");  // Nho return
        }
        if (tmp == Language::GetString(L"TUTORIAL_SHORTCUT")) {
            return NavHost.Navigate("Tutorial");  // Nho return
        }
        if (tmp == Language::GetString(L"ABOUT_SHORTCUT")) {
            return NavHost.Navigate("About");  // Nho return
        }
        if (tmp == Language::GetString(L"EXIT_SHORTCUT")) {
            return NavHost.NavigateStack("ExitScreen");  // Nho return
        }
        // Handle Select
        if (tmp == L"\r") {
            switch (selectedOption) {
                case 0:
                    return NavHost.Navigate("GameModeTypeView");  // Nho return
                case 1:
                    return NavHost.Navigate("LoadScreen");  // Nho return
                case 2:
                    return NavHost.Navigate("ReplayLoad");
                case 3:
                    return NavHost.Navigate("Setting");
                case 4:
                    return NavHost.Navigate("Tutorial");
                case 5:
                    return NavHost.Navigate("About");
                case 6:
                    return NavHost.NavigateStack("ExitScreen");  // Nho return
            }
        }
    }
}
