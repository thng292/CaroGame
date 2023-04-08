#include "Config.h"

std::unordered_map<std::wstring, std::wstring> Config::configDict{};

bool Config::LoadUserSetting()
{
    auto fin = FileHandle::OpenInFile(Constants::USERCONFIG_FILE_PATH);
    if (fin.fail()) {
        return 0;
    }
    //configDict.clear();
    std::wstring buffer;
    while (!fin.eof()) {
        fin >> buffer;
        auto tmp = Utils::LineSplitter(buffer);
        Utils::trim(tmp.first);
        Utils::trim(tmp.second);
        configDict[tmp.first] = tmp.second;
    }
    fin.close();
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
    if (!std::filesystem::exists(Constants::STR_USERCONFIG_PATH)) {
        std::filesystem::create_directory(Constants::STR_USERCONFIG_PATH);
    }
    auto fout = FileHandle::OpenOutFile(Constants::USERCONFIG_FILE_PATH);
    if (fout.fail()) {
        return 0;
    }
    for (const auto& [key, val] : configDict) {
        fout << key << L'=' << val << '\n';
    }
    fout.close();
    return !fout.fail();
}
