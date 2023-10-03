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
      Album *);
    ~Song();

    std::string getName();
    std::string getPath();
    Album * getAlbum();

    void setName(const std::string);
    void setPath(const std::string);
    void setAlbum(Album *);

    void print();

  private:
    std::string name;
    std::string path;
    Album * album;
};

#endif
