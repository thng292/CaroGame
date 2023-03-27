#pragma once
#include <any>
#include <unordered_map>

#include "Constants.h"
#include "FileHandle.h"

namespace Config {

    const std::wstring SoundEffect = L"SoundEffect";
    const std::wstring BGMusic = L"Music";
    const std::wstring UndoOption = L"UndoOption";

    const std::wstring Value_True = L"True";
    const std::wstring Value_False = L"False";

    class Configs {
        static std::unique_ptr<Configs> instance;

       public:
        std::unordered_map<std::wstring, std::wstring> dict;

        static Configs* getInstance()
        {
            if (instance == nullptr) {
                instance = std::make_unique<Configs>();
            }
            return instance.get();
        }
    };

    // Return if the setting is previously exist(first time or not)
    bool LoadUserSetting();

    std::wstring& GetSetting(const std::wstring& name);

    void SetSetting(const std::wstring& name, const std::wstring& data);

    bool SaveUserSetting();
};  // namespace Config