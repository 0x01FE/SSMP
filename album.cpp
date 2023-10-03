#include "album.h"
#include "artist.h"

int index = 0;


Album::Album()
{
    this->name = "";
    this->id = index;
    index++;
}

Album::Album(const std::string name, const std::vector<Artist *> artists)
{
    this->name = name;
    this->id = index;
    this->artists = artists;
    index++;
}

Album::Album(const std::string name, Artist * artist)
{
    this->name = name;
    this->id = index;
    this->artists.push_back(artist);
    index++;
}

Album::~Album() { }

// Getters

std::string Album::getName() { return this->name; }

int Album::getId() { return this->id; }

std::vector<Song> Album::getSongs() { return this->songs; }

std::vector<Artist *> Album::getArtists() { return this->artists; }


// Setters

void Album::setName(const std::string name) { this->name = name; }

void Album::addSong(const Song song) { this->songs.push_back(song); }

void Album::addArtist(Artist * artist) { this->artists.push_back(artist); }

