#include <filesystem>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <stdio.h>
#include <vector>

#include "lib/SimpleIni.h"
#include "lib/split.h"

#include "library.h"

#define MAX_LEN 70

const std::string dash_line = "------------------------------------------------------------";
char user_input[MAX_LEN];

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
        std::cout << "> ";
        std::cin.getline(user_input, MAX_LEN);

        switch (std::stoi(user_input))
        {
            case 1:
                libraryMenu(&music_lib);
                break;
            case 2:
                // TODO @0x01fe : add settings
                break;
            case 3:
                exit(1);
        }
    }

    std::cout << "path is " << library_path << "\n";
}

