#include "album.h"
#include "song.h"
#include <iostream>

Album::Album()
{
    this->name = "";
}

Album::Album(const std::string name, const std::string artist)
{
    this->name = name;
    this->artist = artist;
}

Album::~Album() { }

// Getters

std::string Album::getName() { return this->name; }

std::vector<Song *> Album::getSongs() { return this->songs; }

std::string Album::getArtist() { return this->artist; }


// Setters

void Album::setName(const std::string name) { this->name = name; }

void Album::addSong(Song * song) { this->songs.push_back(song); }

void Album::setArtist(std::string artist) { this->artist = artist; }

// Misc

void Album::print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Artist: " << this->artist << std::endl;

    std::cout << "Songs:" << std::endl;
    for (Song * song : this->songs)
    {
        song->print();
    }

}

