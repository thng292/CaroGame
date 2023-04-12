#pragma once
//#pragma warning(disable : 4996)
#include <codecvt>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

namespace FileHandle {
    const static std::locale LOCALE("vi_Vi.utf8");

    struct FileDetail {
        std::filesystem::path filePath;
        std::filesystem::file_time_type lastModified;
    };

    inline void Ensure(const std::filesystem::path& Dir)
    {
        if (!std::filesystem::exists(Dir)) {
            std::filesystem::create_directories(Dir);
        }
    }

    std::wofstream OpenOutFile(const std::filesystem::path& filePath);

    std::wifstream OpenInFile (const std::filesystem::path& filePath);

    std::vector<FileDetail> GetAllTextFileInDir(
        const std::filesystem::path& Dir
    );

    inline bool Delete(const std::filesystem::path& target) {
        return std::filesystem::remove(target);
    }
};  // namespace FileHandle
