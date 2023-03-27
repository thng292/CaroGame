#include "Config.h"

std::unique_ptr<Config::Configs> Config::Configs::instance = nullptr;

inline std::pair<std::wstring, std::wstring> LineSplitter(
    const std::wstring& line, wchar_t delim = L'='
)
{
    size_t tmp = line.find_first_of(delim);
    return {line.substr(0, tmp), line.substr(tmp + 1)};
}

bool Config::LoadUserSetting()
{
    auto& Settings = Configs::getInstance()->dict;
    auto fin = FileHandle::OpenInFile(Constants::USERCONFIG_FILE_PATH);
    if (fin.fail()) {
        return 0;
    }
    Settings.clear();
    std::wstring buffer;
    while (!fin.eof()) {
        fin >> buffer;
        auto tmp = LineSplitter(buffer);
        Settings[tmp.first] = tmp.second;
    }
    fin.close();
    return 1;
}

std::wstring& Config::GetSetting(const std::wstring& name)
{
    static auto& Settings = Configs::getInstance()->dict;
    return Settings[name];
}

void Config::SetSetting(const std::wstring& name, const std::wstring& data)
{
    static auto& Settings = Configs::getInstance()->dict;
    Settings[name] = data;
}

bool Config::SaveUserSetting()
{
    auto& Settings = Configs::getInstance()->dict;
    if (!std::filesystem::exists(Constants::STR_USERCONFIG_PATH)) {
        std::filesystem::create_directory(Constants::STR_USERCONFIG_PATH);
    }
    auto fout = FileHandle::OpenOutFile(Constants::USERCONFIG_FILE_PATH);
    if (fout.fail()) {
        return 0;
    }
    for (const auto& [key, val] : Settings) {
        fout << key << L'=' << val << '\n';
    }
    fout.close();
    return 1;
}
