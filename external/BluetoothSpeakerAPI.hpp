#pragma once
#include <iostream>
#include <string>

using namespace std;

class BluetoothSpeakerAPI {
public:
    void playSoundViaBluetooth(const string& data) {
        std::cout << "[BluetoothSpeaker] Playing: "<< data << std::endl;
    }
};