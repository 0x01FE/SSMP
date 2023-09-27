#include <filesystem>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <stdio.h>

#define MAX_LEN 70

const std::string dash_line = "------------------------------------------------------------";

void help()
{
    std::cout << dash_line << std::endl;
    std::cout << "[1] Library" << std::endl;
    std::cout << "[2] Settings" << std::endl;
    std::cout << "[3] Exit" << std::endl;
    std::cout << dash_line << std::endl;
}

int main(int argc, char * argv[])
{

    char user_input[MAX_LEN];

    std::cout << "SSMP is a Stated Music Player" << std::endl;
    help();

    for(;;)
    {
        std::cout << "> ";
        std::cin.getline(user_input, MAX_LEN);
    }

    std::string path = ".";

    struct stat sb;

    for (const auto& entry : std::filesystem::directory_iterator(path)) {

        std::filesystem::path outfilename = entry.path();
        std::string outfilename_str = outfilename.string();
        const char* path = outfilename_str.c_str();

        if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR))
            std::cout << "file: " << path << std::endl;
        else
            std::cout << "dir: " << path << "/" << std::endl;
    }
}












