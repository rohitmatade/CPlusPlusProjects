#include <iostream>

#include "../inc/music_playlist.h"

void editPlaylist(Playlist &playlist)
{
    std::string playlistName;
    std::cout << "Which playlist you want to edit? " << std::endl;
    std::cin >> playlistName;
    if (playlist.isPlaylistExists(playlistName))
    {
        std::cout << "Here is list of all the songs present in playlist " << playlistName << ": " << std::endl;
        playlist.printDetailedPlaylist(playlistName);
        while (true)
        {
            std::string operation;
            std::cout << std::endl;
            std::cout << "Enter 'moveup' to move any song up by 1 index" << std::endl;
            std::cout << "Enter 'movedown' to move any song down by 1 index" << std::endl;
            std::cout << "Enter 'swap' to swap any two songs" << std::endl;
            std::cout << "Enter 'delete' to delete any song in playlist" << std::endl;
            std::cout << "Enter 'add' to add any song in playlist" << std::endl;
            std::cout << "Enter 'exit' to exit this menu" << std::endl;
            std::cin >> operation;
            if (operation == "moveup")
            {
                std::string songName;
                std::cout << "Enter the song name you want to move up: ";
                std::cin >> songName;
                if (playlist.isSongExists(playlistName, songName))
                {
                    playlist.moveUp(playlistName, songName);
                }
                else
                {
                    std::cout << songName << " doesn't exists in playlist" << playlistName << std::endl;
                }
            }
            else if (operation == "movedown")
            {
                std::string songName;
                std::cout << "Enter the song name you want to move down: ";
                std::cin >> songName;
                if (playlist.isSongExists(playlistName, songName))
                {
                    playlist.moveDown(playlistName, songName);
                }
                else
                {
                    std::cout << songName << " doesn't exists in playlist " << playlistName << std::endl;
                }
            }
            else if (operation == "swap")
            {
                std::string songNameOne, songNameTwo;
                std::cout << "Enter two song name you want to swap: ";
                std::cin >> songNameOne >> songNameTwo;
                if (playlist.isSongExists(playlistName, songNameOne) && playlist.isSongExists(playlistName, songNameTwo))
                {
                    playlist.swapSongs(playlistName, songNameOne, songNameTwo);
                }
                else
                {
                    if (!playlist.isSongExists(playlistName, songNameOne))
                    {
                        std::cout << songNameOne;
                    }
                    else
                    {
                        std::cout << songNameTwo;
                    }
                    std::cout << " doesn't exists in playlist " << playlistName << std::endl;
                }
            }
            else if (operation == "delete")
            {
                std::string songName;
                std::cout << "Enter the song name you want to delete: ";
                std::cin >> songName;
                if (playlist.isSongExists(playlistName, songName))
                {
                    playlist.deleteSong(playlistName, songName);
                    std::cout << songName << " deleted successfully from playlist " << playlistName << std::endl;
                }
                else
                {
                    std::cout << songName << " doesn't exists in playlist " << playlistName << std::endl;
                }
            }
            else if (operation == "add")
            {
                std::string songName;
                std::cout << "Enter the song name you want to insert: ";
                std::cin >> songName;
                if (existsInDirectory(songName))
                {
                    playlist.addSongToPlaylist(playlistName, songName);
                    std::cout << songName << " added successfully to playlist " << playlistName << std::endl;
                }
                else
                {
                    std::cout << songName << " doesn't exists in directory" << std::endl;
                }
            }
            else if (operation == "exit")
            {
                break;
            }
            else
            {
                std::cout << "Invalid input operation" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Playlist named " << playlistName << " doesn't exists" << std::endl;
    }
}