#include <iostream>

#include "../inc/music_playlist.h"

void createPlaylist(Playlist& playlist)
{
    std::string playlistName;
    std::cout << "Enter the name of playlist: ";
    std::cin >> playlistName;
    playlist.setPlaylistName(playlistName);
    playlist.addPlaylist(playlist);
    std::cout << "Enter the song names you want to add in playlist " << playlistName << std::endl;
    std::cout << "Enter '0' to stop" << std::endl;
    std::string songName;
    while (songName != "0")
    {
        std::cin >> songName;
        if (songName == "0")
        {
            break;
        }
        if (existsInDirectory(songName))
        {
            playlist.addSongToPlaylist(playlistName, songName);
            std::cout << songName << " is successfully added to playlist " << playlistName << std::endl;
        }
        else
        {
            std::cout << songName << " is not present in directory" << std::endl;
        }
    }
    std::cout << playlistName << " playlist has been saved successfully" << std::endl << std::endl;
}