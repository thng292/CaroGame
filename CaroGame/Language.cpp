#include "Language.h"

Dict Language::languageDict{};

Dict Language::ExtractMetaFromFile(
    const std::filesystem::path& filePath
)
{
    auto fin = FileHandle::OpenInFile(filePath);
    Dict res;
    std::wstring inp;
    while (!fin.eof()) {
        std::getline(fin, inp);
        auto tmp = Utils::LineSplitter(inp);
        Utils::trim(tmp.first);
        Utils::trim(tmp.second);
        if (tmp.first[0] != L'[') break;
        res.insert(tmp);
    }
    fin.close();
    return res;
}

void Language::LoadLanguageFromFile(const std::filesystem::path& filePath)
{
    //languageDict.clear();
    auto fin = FileHandle::OpenInFile(filePath);
    std::wstring inp;
    while (!fin.eof()) {
        std::getline(fin, inp);
        auto tmp = Utils::LineSplitter(inp);
        Utils::trim(tmp.first);
        Utils::trim(tmp.second);
        languageDict[tmp.first] = tmp.second;
    }
    fin.close();
}

std::vector<LanguageOption> Language::DiscoverLanguageFile(
    const std::filesystem::path& dirPath
)
{
    std::vector<LanguageOption> res;
    auto files = FileHandle::GetAllTextFileInDir(Constants::LANGUAGE_PATH);
    for (const auto& i : files) {
        res.push_back({ExtractMetaFromFile(i.filePath), i.filePath});
    }
    return res;
}