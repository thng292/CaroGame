#include "Language.h"

inline std::pair<std::wstring, std::wstring> LineSplitter(
    const std::wstring& line, wchar_t delim = L'='
) {
    size_t tmp = line.find_first_of(delim);
    return {line.substr(0, tmp), line.substr(tmp + 1)};
}

Language::LanguageDict Language::ExtractMetaFromFile(
    const std::filesystem::path& filePath
) {
    auto fin = FileHandle::OpenInFile(filePath);
    LanguageDict res;
    std::wstring inp;
    while (!fin.eof()) {
        std::getline(fin, inp);
        auto tmp = LineSplitter(inp);
        Utils::trim(tmp.first);
        Utils::trim(tmp.second);
        if (tmp.first[0] != L'[') break;
        res.insert(tmp);
    }
    fin.close();
    return res;
}

void Language::LoadLanguageFromFile(const std::filesystem::path& filePath) {
    currentLanguageMeta = ExtractMetaFromFile(filePath);
    currentLanguageDict.clear();
    auto fin = FileHandle::OpenInFile(filePath);
    std::wstring inp;
    while (!fin.eof()) {
        std::getline(fin, inp);
        auto tmp = LineSplitter(inp);
        Utils::trim(tmp.first);
        Utils::trim(tmp.second);
        currentLanguageDict.insert(tmp);
    }
    fin.close();
}

std::vector<Language::LanguageOption> Language::DiscoverLanguageFile(
    const std::filesystem::path& dirPath
) {
    std::vector<LanguageOption> res;
    auto files = FileHandle::GetAllTextFileInDir(Constants::LANGUAGE_PATH);
    for (const auto& i : files) {
        res.push_back({ExtractMetaFromFile(i.filePath), i.filePath});
    }
    return res;
}

std::wstring& Language::GetString(const std::wstring& Label) {
    if (!currentLanguageDict.contains(Label)) {
        currentLanguageDict[Label] = Label;
    }
    return currentLanguageDict[Label];
}

std::wstring& Language::GetMeta(const std::wstring& Label) {
    return currentLanguageMeta[Label];
}