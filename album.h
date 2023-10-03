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
    ~Album();

    std::string getName();
    int getId();
    std::vector<Song *> getSongs();
    std::string getArtist();

    void setName(const std::string);
    void addSong(Song *);
    void setArtist(const std::string);

    void print();

  private:
    std::string name;
    std::vector<Song *> songs;
    std::string artist;
};

#endif
