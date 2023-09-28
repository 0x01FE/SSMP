#include <sys/stat.h>
#include <filesystem>

#include "library.h"
#include <taglib/tag.h>

std::vector<std::filesystem::directory_entry> getDirContents(const std::string path)
{

    std::vector<std::filesystem::directory_entry> contents;

    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        contents.push_back(entry);
    }

    return contents;
}

Library::Library(const std::string name, const std::string path)
{
    this->name = name;
    this->path = path;

    auto contents = getDirContents(path);

    this->Albums = std::vector<Album>(0);
}






