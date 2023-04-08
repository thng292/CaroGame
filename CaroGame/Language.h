#pragma once
#include <filesystem>
#include <unordered_map>
#include <vector>

#include "Constants.h"
#include "FileHandle.h"
#include "Utils.h"

namespace Language {
    typedef std::unordered_map<std::wstring, std::wstring> Dict;

    extern Dict languageDict;

    struct LanguageOption {
        Dict meta;
        std::filesystem::path path;
    };

    Dict ExtractMetaFromFile(const std::filesystem::path& filePath);

    void LoadLanguageFromFile(const std::filesystem::path& filePath);

    std::vector<LanguageOption> DiscoverLanguageFile(
        const std::filesystem::path& dirPath = Constants::LANGUAGE_PATH
    );

    std::wstring& GetString(const std::wstring& Label);

    std::wstring& GetMeta(const std::wstring& Label);
}  // namespace Language