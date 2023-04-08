#pragma once
#include <any>
#include <unordered_map>

#include "Constants.h"
#include "FileHandle.h"
#include "Utils.h"

namespace Config {

    const std::wstring SoundEffect = L"SoundEffect";
    const std::wstring BGMusic = L"Music";
    const std::wstring UndoOption = L"UndoOption";
    const std::wstring ThemeFilePath = L"ThemeFilePath";
    const std::wstring LanguageFilePath = L"LanguageFilePath";
    const std::wstring Hint = L"Hint";
    const std::wstring FourWarning = L"FourWarning";

    const std::wstring Value_True = L"True";
    const std::wstring Value_False = L"False";

    extern std::unordered_map<std::wstring, std::wstring> configDict;

    // Return if the setting is previously exist(first time or not)
    bool LoadUserSetting();

    std::wstring& GetConfig(const std::wstring& name);

    void SetConfig(const std::wstring& name, const std::wstring& data);

    bool SaveUserSetting();
};  // namespace Config