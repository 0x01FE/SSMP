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

void Song::print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Path: " << this->path << std::endl;
    std::cout << "Album: " << this->album->getName() << std::endl;
}

