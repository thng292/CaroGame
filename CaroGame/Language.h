#pragma once
#include <filesystem>
#include <unordered_map>
#include <vector>
#include "FileHandle.h"
#include "Constants.h"
#include "Utils.h"

namespace Language {
	typedef std::unordered_map<std::wstring, std::wstring> LanguageDict;

	struct LanguageOption {
		LanguageDict meta;
		std::filesystem::path path;
	};

	static LanguageDict currentLanguageDict;
	static LanguageDict currentLanguageMeta;

	LanguageDict ExtractMetaFromFile(const std::filesystem::path& filePath);

	void LoadLanguageFromFile(const std::filesystem::path& filePath);

	std::vector<LanguageOption> DiscoverLanguageFile(const std::filesystem::path& dirPath = Constants::LANGUAGE_PATH);

	std::wstring& GetString(const std::wstring& Label);

	std::wstring& GetMeta(const std::wstring& Label);
}