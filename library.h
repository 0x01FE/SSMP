#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "album.h"
#include "song.h"
#include "artist.h"

class Library
{
  public:
    Library(const std::string,
        const std::string);
    ~Library();

    std::string getName();
    std::string getPath();
    std::vector<Album *> getAlbums();
    std::vector<Song> getSongs();
    std::vector<Artist> getArtists();

    void setName(const std::string);
    void setPath(const std::string);
    void addAlbum(Album *);
    void removeAlbum(const int);

    Album * searchAlbum(const int);
    Album * searchAlbum(const std::string);

  private:
    std::string name;
    std::string path;
    std::vector<Album *> albums;
};

#endif
