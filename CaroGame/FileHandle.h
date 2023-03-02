#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <string>
#include <vector>
#include <filesystem>

namespace FileHandle {
	const std::locale LOCALE(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>);

	struct FileDetail {
		std::filesystem::path filePath;
		std::filesystem::file_time_type lastModified;
	};

	// Not working !!FUCK!!
	std::wofstream OpenOutFile(const std::filesystem::path& fileName);

	std::wifstream OpenInFile(const std::filesystem::path& fileName);
	
	std::vector<FileDetail> GetAllTextFileInDir(const std::filesystem::path& Dir);
};

