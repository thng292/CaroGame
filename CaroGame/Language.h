#pragma once
#include <filesystem>
#include <unordered_map>
#include <vector>
#include "FileHandle.h"
#include "Constants.h"


namespace Language {
	typedef std::unordered_map<std::wstring, std::wstring> LanguageDict;

	struct LanguageOption {
		LanguageDict meta;
		std::filesystem::path path;
	};

	LanguageDict currentLanguageDict;
	LanguageDict currentLanguageMeta;

	inline std::pair<std::wstring, std::wstring> LineSplitter(const std::wstring& line, wchar_t delim = L'=') {
		size_t tmp = line.find_first_of(delim);
		return { line.substr(0, tmp), line.substr(tmp + 1) };
	}

	LanguageDict ExtractMetaFromFile(const std::filesystem::path& filePath) {
		auto fin = FileHandle::OpenInFile(filePath);
		LanguageDict res;
		std::wstring inp;
		while (!fin.eof())
		{
			std::getline(fin, inp);
			if (inp[0] != L'[') break;
			auto tmp = LineSplitter(inp);
			res[tmp.first] = tmp.second;
		}
		fin.close();
		return res;
	}

	void LoadLanguageFromFile(const std::filesystem::path& filePath) {
		currentLanguageMeta = ExtractMetaFromFile(filePath);
		currentLanguageDict.clear();
		auto fin = FileHandle::OpenInFile(filePath);
		std::wstring inp;
		while (!fin.eof()) {
			std::getline(fin, inp);
			auto tmp = LineSplitter(inp);
			currentLanguageDict[tmp.first] = tmp.second;
		}
		currentLanguageDict[L"Error"] = Constants::STR_ERROR_CANNOT_FIND_LABEL;
		fin.close();
	}


	std::vector<LanguageOption> DiscoverLanguageFile(const std::filesystem::path& dirPath) {
		std::vector<LanguageOption> res;
		auto files = FileHandle::GetAllTextFileInDir(Constants::LANGUAGE_PATH);
		for (const auto& i : files) {
			res.push_back({ ExtractMetaFromFile(i.filePath), i.filePath });
		}
		return res;
	}

	inline std::wstring& GetString(const std::wstring& Label) {
		if (!currentLanguageDict.contains(Label)) {
			return currentLanguageDict[L"Error"];
		}
		return currentLanguageDict[Label];
	}

	inline std::wstring& GetMeta(const std::wstring& Label) {
		return currentLanguageMeta[Label];
	}
}