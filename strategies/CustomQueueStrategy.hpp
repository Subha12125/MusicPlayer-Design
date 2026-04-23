#pragma once
#include <vector>
#include <iostream>
#include "PlayStrategy.hpp"

class CustomQueueStrategy : public PlayStrategy {
public:
    std::vector<Song> play(const std::vector<Song>& songs) override {
        std::cout << "[CustomQueueStrategy] Playing custom user selection.\n";
        // Simple mock: just play the last 3 songs
        if (songs.size() > 3) {
             return std::vector<Song>(songs.end() - 3, songs.end());
        }
        return songs;
    }
};
