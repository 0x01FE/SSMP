#include <sys/stat.h>
#include <filesystem>
#include <iostream>

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
    return nullptr;
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

void getAlbumsInDir(const std::string path, std::vector<Album *> * albums)
{
    // std::cout << "scanning path \"" << path << "\"..." << std::endl;

    struct stat sb;
    std::filesystem::path file_path;
    std::string file_path_str;
    const char * file_path_cstr;

    // std::vector<std::filesystem::directory_entry> contents = getDirContents(path);

    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        file_path = entry.path();
        file_path_str = file_path.string();
        file_path_cstr = file_path_str.c_str();


        if (stat(file_path_cstr, &sb) == 0 && !(sb.st_mode & S_IFDIR))
        {
            TagLib::FileRef file(file_path_cstr);
            if (!file.isNull() && file.tag())
            {
                std::cout << "file name: " << file_path_cstr << std::endl;
                TagLib::Tag * tag = file.tag();

                // Get Artist
                // TODO @0x01FE : support for multiple artists?
                TagLib::String TagLib_artist_name = tag->artist();
                std::string artist_name;

                if (TagLib_artist_name.isEmpty())
                    artist_name = "NULL";
                else
                    artist_name = TagLib_artist_name.to8Bit();


                // Check if album already in memory, if not init
                std::string album_name = tag->album().to8Bit();
                Album * temp_album;

                if (!(temp_album = searchAlbum(album_name, albums)))
                {
                    std::cout << "making new album " << album_name << "..." << std::endl;
                    temp_album = new Album(album_name, artist_name);
                    albums->push_back(temp_album);
                }

                // Init Song
                std::string song_title = tag->title().to8Bit();

                Song * temp_song = new Song(song_title, file_path_cstr, temp_album);

                temp_song->print();

                temp_album->addSong(temp_song);
            }
        }
        else if (file_path_cstr != "" || file_path_cstr != "." || file_path_cstr != "..")
        {
            // std::cout << "dir detected, scanning \"" << file_path_cstr << "\"" << std::endl;
            getAlbumsInDir(file_path_cstr, albums);
        }

    }

}


// Class Functions

Library::Library(const std::string name, const std::string path)
{
    this->name = name;
    this->path = path;

    getAlbumsInDir(path, &this->albums);
    this->print();
}

Library::~Library() { }


// Getters

std::string Library::getName() { return this->name; }

std::string Library::getPath() { return this->path; }

std::vector<Album *> Library::getAlbums() { return this->albums; }

std::vector<Song *> Library::getSongs()
{
    std::vector<Song *> songs;
    for (Album * album : this->albums)
    {
        for (Song * song : album->getSongs())
        {
            songs.push_back(song);
        }
    }

    return songs;
}



// Mutators

void Library::setName(const std::string name) { this->name = name; }

void Library::setPath(const std::string path) { this->path = path; }

void Library::addAlbum(Album * album) { this->albums.push_back(album); }


// Misc

void Library::print()
{
    std::cout << "Album count: " << this->albums.size() << std::endl;
    for (Album * album : this->albums)
    {
        album->print();
    }
}

Album * Library::searchAlbum(const std::string target_name)
{
    for (Album * album : this->albums)
        if (album->getName() == target_name)
            return album;
    return nullptr;
}
