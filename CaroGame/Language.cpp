#include "Language.h"

inline std::pair<std::wstring, std::wstring> LineSplitter(const std::wstring& line, wchar_t delim = L'=') {
	size_t tmp = line.find_first_of(delim);
	return { line.substr(0, tmp), line.substr(tmp + 1) };
}

Language::LanguageDict Language::ExtractMetaFromFile(const std::filesystem::path& filePath) {
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

void Language::LoadLanguageFromFile(const std::filesystem::path& filePath) {
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

std::vector<Language::LanguageOption> Language::DiscoverLanguageFile(const std::filesystem::path& dirPath) {
	std::vector<LanguageOption> res;
	auto files = FileHandle::GetAllTextFileInDir(Constants::LANGUAGE_PATH);
	for (const auto& i : files) {
		res.push_back({ ExtractMetaFromFile(i.filePath), i.filePath });
	}
	return res;
}

std::wstring& Language::GetString(const std::wstring& Label) {
	if (!currentLanguageDict.contains(Label)) {
		return currentLanguageDict[L"Error"];
	}
	return currentLanguageDict[Label];
}

std::wstring& Language::GetMeta(const std::wstring& Label) {
	return currentLanguageMeta[Label];
}