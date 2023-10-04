#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <vector>

class Song;

class Album
{
  public:
    Album();
    Album(const std::string,
      const std::string);
    Album(const std::string);
    ~Album();

    std::string getName();
    int getId();
    std::vector<Song *> getSongs();
    std::vector<std::string> getArtists();
    std::string getArtistsString();

    void setName(const std::string);
    void addSong(Song *);
    void addArtist(const std::string);

    int printSongOptions();

    void print();

  private:
    std::string name;
    std::vector<Song *> songs;
    std::vector<std::string> artists;
};

#endif
