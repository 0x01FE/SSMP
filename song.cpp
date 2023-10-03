#include "song.h"
#include <iostream>

Song::Song() { }

Song::Song(const std::string name, const std::string path, Album * album)
{
    this->name = name;
    this->path = path;
    this->album = album;
}

Song::~Song() { }

// Getters

std::string Song::getName() { return this->name; }

std::string Song::getPath() { return this->path; }

Album * Song::getAlbum() { return this->album; }


// Setters

void Song::setName(const std::string name) { this->name = name; }

void Song::setAlbum(Album * album) { this->album = album; }


// Misc

void Song::Print()
{
    std::printf("Name: %s\n", this->name);
    std::printf("Path: %s\n", this->path);
    std::printf("Album: %d\n", this->album->getName());
}

