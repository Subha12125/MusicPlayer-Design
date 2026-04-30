#pragma once
#include "../models/Playlist.hpp"
#include <iostream>
#include <string>
#include <map>


using namespace std;

class PlaylistManager {
private:
    static PlaylistManager* instance; // Singleton instance
    map<string, Playlist*> playlists; // Map to store playlists by name 
    PlaylistManager() {}


public:
    static PlaylistManager* getInstance() {
        if(!instance) {
            instance = new PlaylistManager();
        }
        return instance;
    }

    void createPlaylist(const string& name) {
        if(playlists.find(name) != playlists.end()) {
            throw runtime_error("Playlist with this name already exists.");
        }
        playlists[name] = new Playlist(name);
    }

    void addSongToPlaylist(const string& playlistName, Song* song) {
        if(playlists.find(playlistName) == playlists.end()) {
            throw runtime_error("Playlist not found.");
        }
        playlists[playlistName]->addSongToPlaylist(song);
    }

    Playlist* getPlaylist(const string& name) {
        if(!playlists.count(name)) {
            throw runtime_error("Playlist not found.");
        }
        return playlists[name];
    }

    PlaylistManager* PlaylistManager::instance = nullptr; // Initialize the singleton instance to nullptr   
};