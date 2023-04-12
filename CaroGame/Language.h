#pragma once
#include <filesystem>
#include <unordered_map>
#include <vector>

#include "Constants.h"
#include "FileHandle.h"
#include "Utils.h"

typedef std::unordered_map<std::wstring, std::wstring> Dict;

struct LanguageOption {
    Dict meta;
    std::filesystem::path path;
};

class Language {
    static Dict languageDict;

   public:
    Language() = delete;

    static Dict ExtractMetaFromFile(const std::filesystem::path& filePath);

    static void LoadLanguageFromFile(const std::filesystem::path& filePath);

    static std::vector<LanguageOption> DiscoverLanguageFile(
        const std::filesystem::path& dirPath = Constants::LANGUAGE_PATH
    );

    static inline const std::wstring& GetString(const std::wstring& Label)
    {
#ifdef LANGUAGE_LABEL_FALLBACK
        if (!languageDict.contains(Label)) {
            languageDict[Label] = Label;
        }
#endif
        return languageDict[Label];
    }

    static inline const std::wstring& GetMeta(const std::wstring& Label)
    {
        return GetString(Label);
    }
};