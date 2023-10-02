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
      const std::vector<int>);
    Song(const std::string,
      const int,
      const int);
    ~Song();

    std::string getName();
    std::string getPath();
    int getId();
    int getAlbum();
    std::vector<int> getArtists();

    void setName(const std::string);
    void setPath(const std::string);
    void setAlbum(const int);
    void addArtist(const int);

    void Print();

  private:
    std::string name;
    std::string path;
    int id;
    int album;
    std::vector<int> artists;
};

#endif
