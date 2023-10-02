#include "artist.h"

int index = 0;

Artist::Artist() { }

Artist::Artist(const std::string name)
{
    this->id = index;
    this->name = name;
    index++;
}

// Getters

std::string Artist::getName() { return this->name; }

int Artist::getId() { return this->id; }

std::vector<int> Artist::getAlbums() { return this->albums; }

// Setters

void Artist::setName(const std::string name) { this->name = name; }

void Artist::setId(const int id) { this->id = id; }

void Artist::addAlbum(const int album_id) { this->albums.push_back(album_id); }



