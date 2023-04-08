#include "Language.h"

Language::Dict Language::languageDict{};

Language::Dict Language::ExtractMetaFromFile(
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
    auto metaDict = ExtractMetaFromFile(filePath);
    languageDict.insert(metaDict.begin(), metaDict.end());
    auto fin = FileHandle::OpenInFile(filePath);
    std::wstring inp;
    while (!fin.eof()) {
        std::getline(fin, inp);
        auto tmp = Utils::LineSplitter(inp);
        Utils::trim(tmp.first);
        Utils::trim(tmp.second);
        languageDict.insert(tmp);
    }
    fin.close();
}

std::vector<Language::LanguageOption> Language::DiscoverLanguageFile(
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

std::wstring& Language::GetString(const std::wstring& Label)
{
#ifdef LANGUAGE_LABEL_FALLBACK
    if (!languageDict.contains(Label)) {
        languageDict[Label] = Label;
    }
#endif
    return languageDict[Label];
}

std::wstring& Language::GetMeta(const std::wstring& Label)
{
    return languageDict[Label];
}