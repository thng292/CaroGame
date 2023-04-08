#include "StartUp.h"

void StartUp::StartUpScreen(NavigationHost& NavHost)
{
    View::Setup();
    bool settingLoadSuccess = Config::LoadUserSetting();
    auto themePath = Config::GetSetting(Config::ThemeFilePath);
    if (!Theme::LoadThemeOrDefault(themePath)) {
        Config::SetSetting(Config::ThemeFilePath, L"");
        Config::SaveUserSetting();
        if (themePath.length()) {
            View::DrawMenuPrevState menuPrevState;
            View::DrawMenuCenter(
                menuPrevState,
                L"",
                {{std::format(L"Can't load theme {}", themePath), 0}},
                -1
            );
            InputHandle::Get();
        }
    }
    if (!settingLoadSuccess ||
        !Config::GetSetting(L"LanguageFilePath").length()) {
        return NavHost.Navigate("FirstTimeLanguageScreen");
    } else {
        Language::LoadLanguageFromFile(
            Config::GetSetting(Config::LanguageFilePath)
        );
        return NavHost.Navigate("MainMenu");
    }
}

void StartUp::FirstTimeLanguageScreen(NavigationHost& NavHost)
{
    Common::DrawHints();
    auto languages = Language::DiscoverLanguageFile();
    static int userSelect = 0;
    std::wstring tmp;
    View::DrawMenuPrevState menuPrevState;

    while (1) {
        auto drawnRect = View::DrawMenuCenter(
            menuPrevState,
            L"",
            {
                {std::format(
                     L"{}: < {} >", languages[userSelect].meta[L"[LANG_SELECT]"],
                 languages[userSelect].meta[L"[LANGUAGE]"]
                 ), 0},
        },
            -1
        );
        tmp = InputHandle::Get();
        if (Config::GetSetting(Config::SoundEffect) == Config::Value_True) {
            Utils::PlayKeyPressSound();
        }
        if (Utils::keyMeanLeft(tmp)) {
            userSelect = Utils::modCycle(userSelect - 1, languages.size());
        }
        if (Utils::keyMeanRight(tmp)) {
            userSelect = Utils::modCycle(userSelect + 1, languages.size());
        }
        if (tmp == L"\r") {
            Config::SetSetting(
                Config::LanguageFilePath,
                languages[userSelect].path.generic_wstring()
            );
            Language::LoadLanguageFromFile(languages[userSelect].path);
            return NavHost.Navigate("FirstTimeMusicScreen");
        }
        View::ClearRect(drawnRect);
    }
}

void StartUp::FirstTimeMusicScreen(NavigationHost& NavHost)
{
    bool userOption =
        Common::ConfirmPrompt(Language::GetString(L"ENABLE_MUSIC_Q"));
    Config::SetSetting(Config::BGMusic, (userOption ? L"True" : L"False"));
    return NavHost.Navigate("FirstTimeSoundEffectScreen");
}

void StartUp::FirstTimeSoundEffectScreen(NavigationHost& NavHost)
{
    bool userOption =
        Common::ConfirmPrompt(Language::GetString(L"ENABLE_SOUND_EFFECT_Q"));
    Config::SetSetting(Config::SoundEffect, (userOption ? L"True" : L"False"));
    Config::SaveUserSetting();
    return NavHost.Navigate("FirstTimeTutorialScreen");
}

void StartUp::FirstTimeTutorialScreen(NavigationHost& NavHost)
{
    bool userOption = Common::ConfirmPrompt(Language::GetString(L"TUTORIAL_Q"));
    NavHost.Navigate("MainMenu");
    if (userOption) {
        return NavHost.Navigate("Tutorial");
    }
}

void StartUp::ExitScreen(NavigationHost& NavHost)
{
    bool userOption =
        Common::ConfirmPrompt(Language::GetString(L"EXIT_CONFIRM_TITLE"));
    if (userOption) {
        return NavHost.NavigateExit();
    } else {
        return NavHost.Back();
    }
}