#pragma once // Include this file only once in the entire program
#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "../models/Playlist.hpp"
#include "PlayStrategy.hpp"

using namespace std;

class RandomPlayStrategy : public PlayStrategy {
private:
    Playlist* currentPlaylist;
    vector<int> remainingSongs;
    stack<Song*> history;

public:
    RandomPlayStrategy() {
        this->currentPlaylist = nullptr;
        srand((unsigned)time(nullptr)); // Seed the random number generator
    }

    void setPlaylist(Playlist* Playlist) override {
        this->currentPlaylist = Playlist;

        if(!currentPlaylist || currentPlaylist->getSize() == 0) return;

        remainingSongs.clear();
        for (int i = 0; i < currentPlaylist->getSize(); ++i) {
            remainingSongs.push_back(i);
        }
        history = stack<Song*>(); // Clear history when a new playlist is set
    }

    bool hasNext() override {
        return currentPlaylist && !remainingSongs.empty();
    }

    //Next in loop
    Song* next() override {
        if (!currentPlaylist || currentPlaylist->getSize() == 0) {
            throw runtime_error("No playlist set or playlist is empty.");
        }

        if(remainingSongs.empty()) {
            throw runtime_error("No songs left to play.");
        }

        int idx = rand() % remainingSongs.size(); // Get a random index
        Song* selectedSong = currentPlaylist->getSongList()[remainingSongs[idx]]; // Get the song at that index

        // Remove the selected index from remainingSongs
        swap(remainingSongs[idx], remainingSongs.back());
        remainingSongs.pop_back();

        history.push(selectedSong); // Add the selected song to history
        return selectedSong;
    }

    bool hasPrevious() override {
        return history.size() > 0;
    }

    Song* previous() override {
        if(history.empty()) {
            throw runtime_error("No previous song in history.");
        }

        Song* song = history.top();
        history.pop();
        return song;
    }
};