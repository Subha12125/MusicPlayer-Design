#pragma once // Include this file only once in the entire program
#include <iostream>
#include "../models/Playlist.hpp"
#include "PlayStrategy.hpp"

using namespace std;

class SequentialPlayStrategy : public PlayStrategy {
private:
    Playlist* currentPlaylist;
    int currentIndex;

public:
    SequentialPlayStrategy() {
        this->currentPlaylist = nullptr;
        this->currentIndex = -1;
    }

    void setPlaylist(Playlist* playlist) override {
        this->currentPlaylist = playlist;
        this->currentIndex = -1; // Reset index when a new playlist is set
    }

    bool hasNext() override {
        return ((currentIndex + 1) < currentPlaylist->getSize());
    }

    // next in loop
    Song* next() override { 
        if(!currentPlaylist || currentPlaylist->getSize() == 0) {
            throw runtime_error("No playlist set or playlist is empty.");
        }
        // Loop back to the start if we reach the end of the playlist
        currentIndex = (currentIndex + 1) % currentPlaylist->getSize(); 
        return currentPlaylist->getSongList()[currentIndex];
    }

    bool hasPrevious() override {
        return (currentIndex -  1 >= 0);
    }

    // previous in loop
    Song* previous() override {
        if(!currentPlaylist || currentPlaylist->getPlaylistName().empty()) {
            throw runtime_error("No playlist set or playlist is empty.");
        }
        // Loop back to the end if we reach the beginning of the playlist
        currentIndex = (currentIndex - 1 + currentPlaylist->getSize()) % currentPlaylist->getSize();
        return currentPlaylist->getSongList()[currentIndex];
    }
};