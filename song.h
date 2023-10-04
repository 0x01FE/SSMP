#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>
#include "album.h"

class Song
{
  public:
    Song();
    Song(const std::string,
      const std::string,
      int,
      const std::string,
      Album *);
    ~Song();

    std::string getName();
    std::string getPath();
    int getTrack();
    std::string getArtist();
    Album * getAlbum();

    void setName(const std::string);
    void setPath(const std::string);
    void setTrack(int);
    void setArtist(const std::string);
    void setAlbum(Album *);

    void print();

  private:
    std::string name;
    std::string path;
    std::string artist;
    int track;
    Album * album;
};

#endif
