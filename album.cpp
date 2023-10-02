#include "album.h"


int index = 0;


Album::Album()
{
    this->name = "";
    this->id = index;
    index++;
}

Album::Album(const std::string name, const std::vector<int> artists)
{
    this->name = name;
    this->id = index;
    this->artists = artists;
    index++;
}

Album::~Album() { }

// Getters

std::string Album::getName() { return this->name; }

int Album::getId() { return this->id; }

std::vector<Song> Album::getSongs() { return this->songs; }

std::vector<int> Album::getArtists() { return this->artists; }


// Setters

void Album::setName(const std::string name) { this->name = name; }

void Album::addSong(const Song song) { this->songs.push_back(song); }

void Album::addArtist(const int artist_id) { this->artists.push_back(artist_id); }

