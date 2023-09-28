#ifndef ARTIST_H
#define ARTIST_H

#include <string>
#include <vector>
#include "song.h"

class Artist
{
  public:
    Artist();
    Artist(const std::string,
      const int,
      const int[]);
    ~Artist();

    std::string getName();
    int getId();
    std::vector<int> getAlbums();

    void setName(const std::string);
    void setId(const int);
    void addAlbum(const int);

  private:
    std::string name;
    int id;
    std::vector<int> albums;
};

#endif
