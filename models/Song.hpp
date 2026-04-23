#pragma once // Include this file only once in the entire program
#include <string>
#include <iostream>

using namespace std;

/**
 * song class has - title, artist, filepath
 */
class Song {
private:
    string title;
    string artist;
    string filepath;

public:
    // Constructor of Song class
    Song(string title, string artist, string filepath) {
        this->title = title;
        this->artist = artist;
        this->filepath = filepath;
    }

    /**
     * - Getters
     */

    string getTitle() {
        return title;
     }

    string getArtist() {
        return artist;
    }

    string getFilePath() {
        return filepath;
    }
};
