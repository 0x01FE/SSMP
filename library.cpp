#include <sys/stat.h>
#include <filesystem>

#include <taglib/taglib.h>
#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/tstring.h>
#include "library.h"


// Helper Functions

Album * searchAlbum(const std::string target_name, std::vector<Album *> * albums)
{
    for (int i = 0; i < albums->size(); i++)
        if (albums->at(i)->getName() == target_name)
            return albums->at(i);

    return nullptr;
}

Album * searchAlbum(const std::string target_name, std::vector<Album *> albums)
{
    for (Album * album : albums)
        if (album->getName() == target_name)
            return album;
}




std::vector<std::filesystem::directory_entry> getDirContents(const std::string path)
{

    std::vector<std::filesystem::directory_entry> contents;

    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        contents.push_back(entry);
    }

    return contents;
}

std::vector<Album *> getAlbumsInDir(const std::string path, std::vector<Album *> albums)
{
    struct stat sb;
    const char * file_path;

    auto contents = getDirContents(path);

    for (auto &entry : contents)
    {
        file_path = entry.path().string().c_str();

        if (stat(file_path, &sb) == 0 && !(sb.st_mode & S_IFDIR))
        {
            TagLib::FileRef file(file_path);
            if (!file.isNull() && file.tag())
            {
                TagLib::Tag * tag = file.tag();

                // Get Artist
                // TODO @0x01FE : support for multiple artists?
                TagLib::String TagLib_artist_name = tag->artist();
                std::string artist_name;

                if (TagLib_artist_name.isNull())
                    artist_name = "NULL";
                else
                    artist_name = TagLib_artist_name.to8Bit();


                // Check if album already in memory, if not init
                std::string album_name = tag->album().to8Bit();
                Album * temp_album;

                if (!(temp_album = searchAlbum(album_name, albums)))
                    temp_album = new Album(album_name, artist_name);

                // Init Song
                Song(tag->title().to8Bit(), file_path, temp_album);

                albums.push_back(temp_album);
            }
        }
        else
        {
            getAlbumsInDir(file_path, albums);
        }
    }

    return albums;
}


// Class Functions

Library::Library(const std::string name, const std::string path)
{
    this->name = name;
    this->path = path;

    this->albums = getAlbumsInDir(path, this->albums);
}

Library::~Library() { }


// Getters

std::string Library::getName() { return this->name; }

std::string Library::getPath() { return this->path; }

std::vector<Album *> Library::getAlbums() { return this->albums; }

std::vector<Song> Library::getSongs() { }



// Mutators

void Library::setName(const std::string name) { this->name = name; }

void Library::setPath(const std::string path) { this->path = path; }

void Library::addAlbum(Album * album) { this->albums.push_back(album); }


// Misc

void Library::removeAlbum(const int album_id) { }

Album * Library::searchAlbum(const std::string target_name)
{
    for (Album * album : this->albums)
        if (album->getName() == target_name)
            return album;
}
