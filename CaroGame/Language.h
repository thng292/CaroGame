#pragma once
#include <filesystem>
#include <unordered_map>
#include <vector>

#include "Constants.h"
#include "FileHandle.h"
#include "Utils.h"

namespace Language {
    typedef std::unordered_map<std::wstring, std::wstring> Dict;

    class LanguageDict {
        static std::unique_ptr<LanguageDict> instance;

       public:
        Dict dict;
        static LanguageDict* getInstance()
        {
            if (instance == nullptr) {
                instance = std::make_unique<LanguageDict>();
            }
            return instance.get();
        }
    };

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