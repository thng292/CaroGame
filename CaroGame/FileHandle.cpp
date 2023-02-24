#include "FileHandle.h"

std::wofstream FileHandle::OpenOutFile(const std::filesystem::path& fileName) {
	std::wofstream fout(fileName);
	fout.imbue(LOCALE);
	return fout;
}

std::wifstream FileHandle::OpenInFile(const std::filesystem::path& fileName) {
	std::wifstream fin(fileName);
	fin.imbue(LOCALE);
	return fin;
}

std::vector<FileHandle::FileDetail> FileHandle::GetAllTextFileInDir(const std::filesystem::path& Dir) {
	std::vector<FileDetail> tmp;
	for (const auto& file : std::filesystem::directory_iterator(Dir)) {
		if (file.is_character_file()) {
			tmp.push_back({ file.path(), file.last_write_time()});
		}
	}
	return tmp;
}

