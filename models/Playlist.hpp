#pragma once // Include this file only once in the entire program
#include <string>
#include <iostream>
#include <vector>
#include "Song.hpp"

using namespace std;

/**
 * playlist class has - playlistName, songList<vector of Song*>
*/

class Playlist {
private:
    string playlistName;
    vector<Song*> songList;
    
    public:
    // Constructor
    Playlist(string playlistName) {
        this->playlistName = playlistName;
    }

    /**
     * - Getters
    */

    string getPlaylistName() {
        return playlistName;
    }

    const vector<Song*>& getSongList() {
        return songList;
    }

    int getSize() {
        return (int)songList.size();
    }

    void addSongToPlaylist(Song* song) {
        if(song == nullptr) {
            throw runtime_error("Cannot add a null song to the playlist.");
        }
        songList.push_back(song);
    }
};