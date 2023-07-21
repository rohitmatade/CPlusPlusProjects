#include <iostream>
#include <vector>
#include <algorithm>

#include "../inc/music_playlist.h"

std::vector<Playlist> playlists;

void Playlist::setPlaylistName(const std::string& name)
{
    this->name = name;
}

int Playlist::printPlaylistNames()
{
    for(auto& playlist : playlists)
    {
        std::cout << "- " << playlist.name << std::endl;
    }
    return playlists.size();
}

void Playlist::addPlaylist(const Playlist& playlist)
{
    playlists.push_back(playlist);
}

bool Playlist::isPlaylistExists(const std::string& name)
{
    bool exist = false;
    for(auto& playlist : playlists)
    {
        if(playlist.name == name)
        {
            exist = true;
        }
    }
    return exist;
}

void Playlist::printDetailedPlaylist(const std::string& name)
{
    for(auto& playlist : playlists)
    {
        if(playlist.name == name)
        {
            for(auto song : playlist.songs)
            {
                std::cout << "- " << song << std::endl;
            }
        }
    }
}

bool Playlist::isSongExists(const std::string& playlistName, const std::string& songName)
{
    bool exist = false;
    for(auto& playlist : playlists)
    {
        if(playlist.name == playlistName)
        {
            for(auto song : playlist.songs)
            {
                if(song == songName)
                exist = true;
            }
        }
    }
    return exist;
}

void Playlist::moveUp(const std::string& playlistName, const std::string& songName)
{
    for(auto& playlist : playlists)
    {
        if(playlist.name == playlistName)
        {
            auto iterator = std::find(playlist.songs.begin(), playlist.songs.end(), songName);
            if(iterator != playlist.songs.begin())
            {
                std::iter_swap(iterator, iterator - 1);
                std::cout << songName << " moved up by one index successfully" << std::endl;
            }
            else
            {
                std::cout << songName << " is already on the top." << std::endl;
            }
            break;
        }
    }
}

void Playlist::moveDown(const std::string& playlistName, const std::string& songName)
{
    for(auto& playlist : playlists)
    {
        if(playlist.name == playlistName)
        {
            auto iterator = std::find(playlist.songs.begin(), playlist.songs.end(), songName);
            if(iterator != playlist.songs.end() - 1)
            {
                std::iter_swap(iterator, iterator + 1);
                std::cout << songName << " moved down by one index successfully" << std::endl;
            }
            else
            {
                std::cout << songName << " is already at the bottom." << std::endl;
            }
            break;
        }
    }
}

void Playlist::swapSongs(const std::string& playlistName, const std::string& songNameOne, const std::string& songNameTwo)
{
    for(auto& playlist : playlists)
    {
        if(playlist.name == playlistName)
        {
            auto iteratorOne = std::find(playlist.songs.begin(), playlist.songs.end(), songNameOne);
            auto iteratorTwo = std::find(playlist.songs.begin(), playlist.songs.end(), songNameTwo);
            if(iteratorOne != iteratorTwo)
            {
                std::iter_swap(iteratorOne, iteratorTwo);
            }
            break;
        }
    }
}

void Playlist::deleteSong(const std::string& playlistName, const std::string& songName)
{
    for(auto& playlist : playlists)
    {
        if(playlist.name == playlistName)
        {
            auto iterator = std::find(playlist.songs.begin(), playlist.songs.end(), songName);
            playlist.songs.erase(iterator);
            break;
        }
    }
}

void Playlist::addSongToPlaylist(const std::string& playlistName, const std::string& songName)
{
    for(auto& playlist : playlists)
    {
        if(playlist.name == playlistName)
        {
            playlist.songs.push_back(songName);
            break;
        }
    }
}

std::string Playlist::returnSongName(const std::string& playlistName, const int& index)
{
    std::string songName;
    for(auto& playlist : playlists)
    {
        if(playlist.name == playlistName)
        {
            if(index < playlist.songs.size())
            {
                songName = playlist.songs.at(index);
            }
            else
            {
                std::cout << "End of playlist " << playlistName << std::endl;
                songName = "stop";
            }
        }
    }
    return songName;
}