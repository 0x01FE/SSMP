#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "album.h"
#include "song.h"

class Library
{
  public:
    Library(const std::string,
        const std::string);
    ~Library();

    std::string getName();
    std::string getPath();
    std::vector<Album *> getAlbums();
    std::vector<Song *> getSongs();

    void setName(const std::string);
    void setPath(const std::string);
    void addAlbum(Album *);

    Album * searchAlbum(const std::string);

    void print();

  private:
    std::string name;
    std::string path;
    std::vector<Album *> albums;
};

#endif
