#pragma once
#include <iostream>
#include <string>

using namespace std;

class HeadphonesAPI {
public:
    void playSoundViaCable(const string& data) {
        std::cout << "[Headphones] Playing: "<< data << std::endl;
    }
};