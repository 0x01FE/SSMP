#include "song.h"
#include <iostream>


int index = 0;



Song::Song() { }

Song::Song(const std::string name, const int album, std::vector<int> artists)
{
    this->name = name;
    this->id = index;
    this->album = album;
    this->artists = artists;
    index++;
}

Song::Song(const std::string name, const int album, const int artist)
{
    this->name = name;
    this->id = index;
    this->album = album;
    this->artists.push_back(artist);
    index++;
}

Song::~Song() { }

// Getters

std::string Song::getName() { return this->name; }

std::string Song::getPath() { return this->path; }

int Song::getId() { return this->id; }

int Song::getAlbum() { return this->album; }

std::vector<int> Song::getArtists() { return this->artists; }

// Setters

void Song::setName(const std::string name) { this->name = name; }

void Song::setAlbum(const int album_id) { this->album = album_id; }

void Song::addArtist(const int artist_id) { this->artists.push_back(artist_id); }


// Misc

void Song::Print()
{
    std::printf("Name: %s\n", this->name);
    std::printf("Path: %s\n", this->path);
    std::printf("Id: %d\n", this->id);
    std::printf("Album Id: %d\n", this->album);
    std::printf("Artists:\n");
    for (int artist : this->artists)
        std::printf("   %s\n", artist);
}

