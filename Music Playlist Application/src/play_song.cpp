#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "../inc/music_playlist.h"

enum playingOptions
{
    START = 'S',
    PLAY_PAUSE = 'P',
    NEXT_SONG = '>',
    PREVIOUS_SONG = '<',
    EXIT = 'E'
};

void playSong(const std::string& playlistName, Playlist& playlist)
{
    SDL_Init(SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    char choice;
    bool playing = false, start = false;
    std::cout << "  - 'S' to play the song from begining" << std::endl;
    std::cout << "  - 'P' to play/pause the song" << std::endl;
    std::cout << "  - '>S' to play next song" << std::endl;
    std::cout << "  - '<S' to play previous song" << std::endl;
    std::cout << "  - 'E' to exit" << std::endl;
    int songIndex = 0;
    while(choice != EXIT)
    {
        std::cin >> choice;
        if(choice >= 'a' && choice <= 'z')
        {
            choice = choice - 32;
        }
        std::string songName = playlist.returnSongName(playlistName, songIndex);
        std::string filename = "songs/" + songName;
        Mix_Music *music = Mix_LoadMUS(filename.c_str());
        switch (choice)
        {
            case START:
                Mix_PlayMusic(music, -1);
                playing = true;
                start = true;
                if(songName == "stop")
                {
                    Mix_HaltMusic();
                }
                else
                {
                    std::cout << "Starting " << songName << " from the begining..." << std::endl; 
                }
                break;

            case PLAY_PAUSE:
                if(!start)
                {
                    Mix_PlayMusic(music, -1);
                    playing = true;
                    start = true;
                    std::cout << "Playing " << songName << std::endl;  
                }
                else
                {
                    if(playing)
                    {
                        Mix_PauseMusic();
                        playing = false;
                        std::cout << "Song paused" << std::endl;
                    }
                    else
                    {
                        Mix_ResumeMusic();
                        playing = true;
                        std::cout << "Song resumed" << std::endl;
                    }
                }
                break;

            case NEXT_SONG:
                songIndex++;
                break;

            case PREVIOUS_SONG:
                songIndex--;
                break;

            case EXIT:
                Mix_FreeMusic(music);
                Mix_CloseAudio();
                Mix_Quit();
                SDL_Quit();
                break;
            
            default:
                std::cout << "INVALID INPUT" << std::endl;
                break;
        }
    }
}