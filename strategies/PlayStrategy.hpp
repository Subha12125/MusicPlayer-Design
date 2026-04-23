#pragma once // Include this file only once in the entire program
#include <iostream>
#include "../models/Song.hpp"
#include "../models/Playlist.hpp"

using namespace std;

// This is the base class for all play strategies.
// It defines the interface for playing songs from a playlist.

/**
 * - PlayStrategy
 * - setPlaylist
 * - next
 * - hasNext
 * - previous
 * - hasPrevious
 * - addToNext
*/
class PlayStrategy {
public:
    
    virtual ~PlayStrategy() {}
    virtual void setPlaylist(Playlist* Playlist) = 0;
    virtual Song* next() = 0;
    virtual bool hasNext() = 0;
    virtual Song* previous() = 0;
    virtual bool hasPrevious() = 0;
    virtual void addToNext(Song* song) {}

};