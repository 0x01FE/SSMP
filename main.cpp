#include <filesystem>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <stdio.h>
#include <vector>
#include <thread>

#include <ao/ao.h>
#include <mpg123.h>

#include "lib/SimpleIni.h"
#include "lib/split.h"

#include "library.h"

#define MAX_LEN 70
#define BITS 8

const std::string dash_line = "------------------------------------------------------------";
char user_input[MAX_LEN];
std::thread * playing;


void play(std::string const& path)
{
    std::cout << "in thread path: " << path.c_str() << std::endl;
    mpg123_handle * mh;
    char * buffer;
    size_t buffer_size;
    size_t done;
    int err;

    int driver;
    ao_device *dev;

    ao_sample_format format;
    int channels, encoding;
    long rate;

    /* initializations */
    ao_initialize();
    driver = ao_default_driver_id();
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    buffer_size = mpg123_outblock(mh);
    buffer = (char *) malloc(buffer_size * sizeof(char));

    /* open the file and get the decoding format */
    mpg123_open(mh, path.c_str());
    mpg123_getformat(mh, &rate, &channels, &encoding);

    /* set the output format and open the output device */
    format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;

    /* decode and play */

    ao_device * device = ao_open_live(driver, &format, NULL);

    while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
        ao_play(dev, buffer, done);


    /* clean up */
    free(buffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();
}

void help()
{
    std::cout << dash_line << "\n";
    std::cout << "[1] Library\n";
    std::cout << "[2] Settings\n";
    std::cout << "[3] Exit\n";
    std::cout << dash_line << "\n";
}

int promptInput()
{
    std::printf("> ");
    std::cin.getline(user_input, MAX_LEN);

    char* p;
    std::strtol(user_input, &p, 10);

    if (*p == 0)
        return std::stoi(user_input);
    else
    {
        std::printf("Input was not a number. Please try again.\n");
        return promptInput();
    }
}


// TODO @0x01fe : add paging feature
void libraryMenu(Library * music_lib)
{
    std::printf("Please select an album.\n");
    int exit_index = music_lib->printAlbumOptions() + 1;
    std::printf("[%d] Back\n", exit_index);

    int selected_option = promptInput();

    if (selected_option == exit_index)
        return;

    int selected_index = selected_option - 1;

    Album * selected_album = music_lib->getAlbum(selected_index);

    std::printf("Please select a song to play.\n");
    exit_index = selected_album->printSongOptions() + 1;
    std::printf("[%d] Back\n", exit_index);
    selected_option = promptInput();

    if (selected_option == exit_index)
        libraryMenu(music_lib);

    selected_index = selected_option - 1;

    Song * selected_song = selected_album->getSong(selected_index);

    selected_song->print();

    std::printf("Now playing %s by %s...\n", selected_song->getName().c_str(), selected_song->getArtist().c_str());
    // std::fflush(stdout);

    // const char * song_path = music_lib->getAlbum(selected_index)->getSong(selected_index)->getPath().c_str();

    std::cout << "before thread direct: " << music_lib->getAlbum(selected_index)->getSong(selected_index)->getPath().c_str() << std::endl;
    std::string song_path_str = music_lib->getAlbum(selected_index)->getSong(selected_index)->getPath().string();
    std::cout << "before thread string: " << song_path_str << std::endl;
    std::cout << "before thread string to c_str: " << song_path_str.c_str() << std::endl;

    const char * song_path = song_path_str.c_str();

    std::cout << "before thread c_str var: " << song_path << std::endl;


    playing = new std::thread(play, song_path_str);
}



int main(int argc, char * argv[])
{

    // Get config data
    CSimpleIni ini;
    ini.SetUnicode();

    // TODO : @0x01fe Add error handling
    ini.LoadFile("config.ini");

    bool multiValue;
    const char * library_path;
    library_path = ini.GetValue("LIBRARY", "LIBRARIES", nullptr, &multiValue);

    // std::vector<std::string> library_pathes = split(library_path, ',');

    // for (auto s : library_pathes)
    //     std::cout << s << "\n";

    Library music_lib("foo", library_path);

    std::cout << "SSMP is a Stated Music Player\n";
    help();

    for(;;)
    {
        int selected_input = promptInput();

        switch (selected_input)
        {
            case 1:
                libraryMenu(&music_lib);
                break;
            case 2:
                // TODO @0x01fe : add settings
                break;
            case 3:
                exit(1);
            case 4:
                music_lib.print();
                break;
            case 5:
                std::cout << music_lib.getAlbum(1)->getSong(1)->getPath().c_str() << std::endl;
        }
    }

    std::cout << "path is " << library_path << "\n";
}

