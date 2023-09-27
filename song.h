#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>

class Song
{
  public:
    Song();
    Song(const std::string,
      const int,
      const int,
      const std::vector<int>);

    std::string getName();
    int getId();
    int getAlbum();
    std::vector<int> getArtists();

    void setName(std::string);
    void setId(const int);
    void setAlbum(const int);
    void addArtist(const int);

    void Print();

  private:
    std::string name;
    int id;
    int album;
    std::vector<int> artists;
};

#endif
