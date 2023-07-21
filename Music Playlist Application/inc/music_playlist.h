#ifndef MUSIC_PLAYLIST
#define MUSIC_PLAYLIST

#include <iostream>
#include <vector>

class Playlist;

void printSongsInDirectory();
bool existsInDirectory(const std::string& song_name);
void createPlaylist(Playlist& playlist);
void viewPlaylist(Playlist &playlist);
void editPlaylist(Playlist &playlist);
void playSong(const std::string& playlistName, Playlist& playlist);

class Playlist 
{
    private:
        std::string name;
        std::vector<std::string> songs;
    public:
        void setPlaylistName(const std::string& name);
        int printPlaylistNames();
        void addPlaylist(const Playlist& playlist);
        bool isPlaylistExists(const std::string& name);
        void printDetailedPlaylist(const std::string& name);
        bool isSongExists(const std::string& playlistName, const std::string& songName);
        void moveUp(const std::string& playlistName, const std::string& songName);
        void moveDown(const std::string& playlistName, const std::string& songName);
        void swapSongs(const std::string& playlistName, const std::string& songNameOne, const std::string& songNameTwo);
        void deleteSong(const std::string& playlistName, const std::string& songName);
        void addSongToPlaylist(const std::string& playlistName, const std::string& songName);
        std::string returnSongName(const std::string& playlistName, const int& index);
};

#endif
