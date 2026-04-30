#pragma once
#include "../models/Song.hpp"
#include "../device/IAudioOutputDevice.hpp"
#include <string.h>
#include <iostream>

using namespace std;

class AudioEngine {
private:
    Song* currentSong;
    bool songIsPaused;

public:
    AudioEngine() {
        currentSong = nullptr;
        songIsPaused = false;
    }    

    string getCurrentSongTitle() {
        if (currentSong) {
            return currentSong->getTitle();
        } else {
            return "";
        }
    }

    bool isPaused() {
        return songIsPaused;
    }

    void play(IAudioOutputDevice* aod, Song* song) {
        if(song == nullptr) {
            throw runtime_error("No song provided to play.");
        }

        // If the song is paused and it's the same song, resume it
        if(songIsPaused && song == currentSong) {
            cout << "Resuming song: " << song->getTitle() << endl;
            songIsPaused = false;
        } else {
            cout << "Playing song: " << song->getTitle() << endl;
            aod->playAudio(song);
            currentSong = song;
            songIsPaused = false;
        } 
    }

    void pause() {
        if(currentSong == NULL) {
            throw runtime_error("No song is currently playing to pause.");
        }

        if(songIsPaused) {
            throw runtime_error("Song is already paused.");
        }

        songIsPaused = true;
        cout << "Paused song: " << currentSong->getTitle() << endl;
    }
};

