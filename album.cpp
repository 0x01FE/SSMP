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
    this->artists.push_back(artist);
}

Album::Album(const std::string name)
{
    this->name = name;
}

Album::~Album() { }

// Getters

std::string Album::getName() { return this->name; }

std::vector<Song *> Album::getSongs() { return this->songs; }

std::vector<std::string> Album::getArtists() { return this->artists; }

// TODO @0x01fe : sort artists by number of tracks in the album
std::string Album::getArtistsString()
{
    std::string artists_str;

    for (std::string artist : this->artists)
    {
        if (artist == (this->artists.at(artists.size()-1)))
            artists_str = artists_str + artist;
        else
           artists_str = artists_str + artist + ", ";
    }

    return artists_str;
}

// Setters

void Album::setName(const std::string name) { this->name = name; }

void Album::addSong(Song * song)
{
    this->songs.push_back(song);
    std::string new_artist = song->getArtist();

    bool in_vector = false;
    for (std::string artist : this->artists)
    {
        if (artist == new_artist)
        {
            in_vector = true;
            break;
        }
    }

    if (!in_vector)
        this->artists.push_back(new_artist);
}

void Album::addArtist(std::string artist) { this->artists.push_back(artist); }

// Misc

int Album::printSongOptions()
{
    Song * song;
    int index = 0;
    for (; index < this->songs.size(); index++)
    {
        song = this->songs[index];
        std::printf("[%d] %s - %s\n", index + 1, song->getName().c_str(), song->getArtist().c_str());
    }

    return index;
}

void Album::print()
{
    std::cout << "Name: " << this->name << std::endl;

    std::cout << "Artists: ";
    for (std::string artist : this->artists)
        std::cout << artist << " ";
    std::cout << std::endl;

    std::cout << "Songs:" << std::endl;
    for (Song * song : this->songs)
    {
        song->print();
    }

}

