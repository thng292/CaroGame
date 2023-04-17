#include "Config.h"

std::unordered_map<std::wstring, std::wstring> Config::configDict{};

bool Config::LoadUserSetting()
{
    auto fin = FileHandle::OpenInFile(Constants::USERCONFIG_FILE_PATH);
    if (fin.fail()) {
        return 0;
    }
    std::wstring buffer;
    while (!fin.eof()) {
        fin >> buffer;
        auto tmp = Utils::LineSplitter(buffer);
        Utils::trim(tmp.first);
        Utils::trim(tmp.second);
        configDict[tmp.first] = tmp.second;
    }
    return 1;
}

std::wstring& Config::GetConfig(const std::wstring& name)
{
    return configDict[name];
}

void Config::SetConfig(const std::wstring& name, const std::wstring& data)
{
    configDict[name] = data;
}

bool Config::SaveUserSetting()
{
    auto fout = FileHandle::OpenOutFile(Constants::USERCONFIG_FILE_PATH);
    for (const auto& [key, val] : configDict) {
        fout << key << L'=' << val << '\n';
    }
    return !fout.fail();
}
