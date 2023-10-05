#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>
#include <filesystem>
#include "album.h"

class Song
{
  public:
    Song();
    Song(const std::string,
      std::filesystem::path,
      int,
      const std::string,
      Album *);
    ~Song();

    std::string getName();
    std::filesystem::path getPath();
    int getTrack();
    std::string getArtist();
    Album * getAlbum();

    void setName(const std::string);
    void setPath(std::filesystem::path);
    void setTrack(int);
    void setArtist(const std::string);
    void setAlbum(Album *);

    void print();

  private:
    std::string name;
    std::filesystem::path path;
    std::string artist;
    int track;
    Album * album;
};

#endif
