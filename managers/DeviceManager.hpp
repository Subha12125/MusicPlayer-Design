#pragma once
#include <iostream>
#include "../device/IAudioOutputDevice.hpp"
#include "../enums/DeviceType.hpp"
#include "../factories/DeviceFactory.hpp"

using namespace std;
/**
 * DeviceManager is a singleton class responsible
 * for managing audio output devices in the music player application. It allows connecting to different types of devices (Bluetooth, Wired, Headphones) and provides a unified interface for playing audio through the connected device. The DeviceManager ensures that only one device is connected at a time and handles the lifecycle of the connected device.
 */
class DeviceManager {
private:
    static DeviceManager* instance;
    IAudioOutputDevice* currentOutputDevice;

    // Private constructor to prevent instantiation
    DeviceManager() {
        currentOutputDevice = nullptr;
    }

public:
    static DeviceManager* getInstance() {
        if(instance == NULL) {
            instance = new DeviceManager();
        }

        return instance;
    }
    void connect(DeviceType devicetype) {
        if (currentOutputDevice) {
            cout << "Disconnecting current device..." << endl;
            delete currentOutputDevice; // Clean up the existing device
            currentOutputDevice = nullptr;
        }

        // Create a new device using the factory
        currentOutputDevice = DeviceFactory::createDevice(devicetype);

        // Simulate connection process
        switch (devicetype)
        {
            case DeviceType::BLUETOOTH:
                cout << "Connecting to Bluetooth device..." << endl;
                break;

            case DeviceType::WIRED:
                cout << "Connecting to Wired device..." << endl;    
                break;
            case DeviceType::HEADPHONES:
                cout << "Connecting to Headphones..." << endl;
                break;
            
            default:
                break;
        }
    }

    // Get the currently connected output device
    IAudioOutputDevice* getOutputDevice() {
        if(!currentOutputDevice) {
            throw runtime_error("No output device connected.");
        }
        return currentOutputDevice;
    }

    bool hasOutputDevice() {
        return currentOutputDevice != nullptr;
    }
};

DeviceManager* DeviceManager::instance = nullptr; // Initialize the static instance pointer to nullptr