#include "FileHandle.h"

std::wofstream FileHandle::OpenOutFile(const std::filesystem::path& filePath)
{
    if (filePath.has_parent_path()) {
        Ensure(filePath.parent_path());
    }
    std::wofstream fout(filePath);
    fout.imbue(LOCALE);
    return fout;
}

std::wifstream FileHandle::OpenInFile(const std::filesystem::path& filePath)
{
    if (filePath.has_parent_path()) {
        Ensure(filePath.parent_path());
    }
    std::wifstream fin(filePath);
    fin.imbue(LOCALE);
    return fin;
}

std::vector<FileHandle::FileDetail> FileHandle::GetAllTextFileInDir(
    const std::filesystem::path& Dir
)
{
    std::vector<FileDetail> tmp;
    Ensure(Dir);
    for (const auto& file : std::filesystem::directory_iterator(Dir)) {
        if (file.is_regular_file()) {
            tmp.push_back({file.path(), file.last_write_time()});
        }
    }
    return tmp;
}
