#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "../inc/music_playlist.h"

enum Options
{
    EXIT,
    LIST_ALL_SONGS,
    CREATE_PLAYLIST,
    VIEW_PLAYLIST,
    EDIT_PLAYLIST,
    PLAY_SONG
};

int main()
{
    int choice;
    Playlist playlist;
    while(true)
    {
        std::cout << "Press 1 to List all the songs present in the directory" << std::endl;
        std::cout << "      2 to Create playlist" << std::endl;
        std::cout << "      3 to View all playlist" << std::endl;
        std::cout << "      4 to Edit playlist" << std::endl;
        std::cout << "      5 to play the songs" << std::endl;
        std::cout << "      0 to Exit" << std::endl;
        std::cin >> choice;
        switch(choice)
        {
            case LIST_ALL_SONGS:
                std::cout << "HERE IS THE LIST OF ALL SONGS PRESENT IN OUR DIRECTORY" << std::endl;
                printSongsInDirectory();
                std::cout << std::endl;
                break;

            case CREATE_PLAYLIST:
                createPlaylist(playlist);
                break;

            case VIEW_PLAYLIST:
            {
                int numberOfplaylist = playlist.printPlaylistNames();
                if (numberOfplaylist == 0)
                {
                    std::cout << "It doesn't exist any playlist" << std::endl;
                }
                else
                {
                    viewPlaylist(playlist);
                }
                break;
            }

            case EDIT_PLAYLIST:
            {
                int numberOfplaylist = playlist.printPlaylistNames();
                if (numberOfplaylist == 0)
                {
                    std::cout << "It doesn't exist any playlist" << std::endl;
                }
                else
                {
                    editPlaylist(playlist);
                }
                break;
            }
                
            case PLAY_SONG:
            {
                int numberOfplaylist = playlist.printPlaylistNames();
                if(numberOfplaylist == 0)
                {
                    std::cout << "It doesn't exist any playlist" << std::endl;
                }
                else
                {
                    std::string playlistName;
                    std::cout << "Enter the playlist name you want to start playing" << std::endl;
                    std::cin >> playlistName;
                    if(playlist.isPlaylistExists(playlistName))
                    {
                        playSong(playlistName, playlist);
                    }
                    else
                    {
                        std::cout << "Playlist " << playlistName << "doesn't exist" << std::endl;
                    }
                }
                break;
            }
            case EXIT:
                exit(0);

            default:
                std::cout << "Invalid input" << std::endl;
                break;
        }
    }
    return 0;
}