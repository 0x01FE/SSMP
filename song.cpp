#include "song.h"
#include <iostream>

Song::Song() { }

Song::Song(const std::string name, std::filesystem::path path, int track, const std::string artist, Album * album)
{
    this->name = name;
    this->path = path;
    this->track = track;
    this->artist = artist;
    this->album = album;
}

Song::~Song() { }

// Getters

std::string Song::getName() { return this->name; }

std::filesystem::path Song::getPath() { return this->path; }

int Song::getTrack() { return this->track; }

std::string Song::getArtist() { return this->artist; }

Album * Song::getAlbum() { return this->album; }


// Setters

void Song::setName(const std::string name) { this->name = name; }

void Song::setPath(const std::filesystem::path path) { this->path = path; }

void Song::setTrack(int track) { this->track = track; }

void Song::setArtist(const std::string artist) { this->artist = artist; }

void Song::setAlbum(Album * album) { this->album = album; }


// Misc

void Song::print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Path: " << this->path.c_str() << std::endl;
    std::cout << "Track #: " << this->track << std::endl;
    std::cout << "Artist: " << this->artist << std::endl;
    std::cout << "Album: " << this->album->getName() << std::endl;
}

