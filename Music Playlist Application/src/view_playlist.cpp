#include <iostream>

#include "../inc/music_playlist.h"

void viewPlaylist(Playlist &playlist)
{
        std::string playlistName;
        std::cout << "Enter the playlist name you want to see in detail: ";
        std::cin >> playlistName;
        if (playlist.isPlaylistExists(playlistName))
        {
            playlist.printDetailedPlaylist(playlistName);
        }
        else
        {
            std::cout << "Playlist named " << playlistName << " doesn't exists" << std::endl;
        }
        std::cout << std::endl;
}