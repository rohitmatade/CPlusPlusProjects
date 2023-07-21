#include <iostream>
#include <dirent.h>
#include <filesystem>

void printSongsInDirectory()
{

    DIR* directory = opendir("./songs");
    dirent* entry;
    int index = 1;
    while((entry = readdir(directory)) != nullptr)
    {
        if(entry->d_name[0] == '.' && (entry->d_name[1] == '\0' || (entry->d_name[1] == '.' && entry->d_name[2] == '\0')))
        {
            continue;
        }
        std::cout << index << " " << entry->d_name << '\n';
        index ++;
    }
    closedir(directory);
}

bool existsInDirectory(const std::string& song_name)
{
    bool present;
    std::string filename = "./songs/" + song_name;
    if(std::filesystem::exists(filename))
    {
        present = true;
    }
    else
    {
        present = false;
    }
    return present;
}