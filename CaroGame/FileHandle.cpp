#include "FileHandle.h"

std::wofstream FileHandle::OpenOutFile(
    const std::filesystem::path& filePath, std::ios::openmode mode
)
{
    if (filePath.has_parent_path()) {
        Ensure(filePath.parent_path());
    }
    std::wofstream fout(filePath, mode);
    fout.imbue(LOCALE);
    return fout;
}

std::wifstream FileHandle::OpenInFile(
    const std::filesystem::path& filePath, std::ios::openmode mode
)
{
    if (filePath.has_parent_path()) {
        Ensure(filePath.parent_path());
    }
    std::wifstream fin(filePath, mode);
    fin.imbue(LOCALE);
    return fin;
}

std::vector<FileHandle::FileDetail> FileHandle::GetAllTextFileInDir(
    const std::filesystem::path& Dir
)
{
    std::vector<FileDetail> res;
    Ensure(Dir);
    for (auto& file : std::filesystem::directory_iterator(Dir)) {
        if (file.is_regular_file()) {
            res.emplace_back(file.path(), file.last_write_time());
        }
    }
    return res;
}
