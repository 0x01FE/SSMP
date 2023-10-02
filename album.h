#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <vector>
#include "song.h"

class Album
{
  public:
    Album();
    Album(const std::string,
      const std::vector<int>);
    ~Album();

    std::string getName();
    int getId();
    std::vector<Song> getSongs();
    std::vector<int> getArtists();

    void setName(const std::string);
    void addSong(const Song);
    void addArtist(const int);

  private:
    std::string name;
    int id;
    std::vector<Song> songs;
    // Artists are stored in an album as their id
    std::vector<int> artists;
};

#endif
