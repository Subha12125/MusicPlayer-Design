#pragma once
#include <iostream>
#include "../strategies/SequentialPlayStrategy.hpp"
#include "../strategies/CustomQueueStrategy.hpp"
#include "../strategies/RandomPlayStrategy.hpp"
#include "../strategies/PlayStrategy.hpp"
#include "../enums/PlayStrategyType.hpp"

using namespace std;

class StrategyManager {
private:
    static StrategyManager* instance;
    SequentialPlayStrategy* sequentialStrategy;
    RandomPlayStrategy* randomStrategy;
    CustomQueueStrategy* customQueueStrategy;

    StrategyManager() {
        sequentialStrategy = new SequentialPlayStrategy();
        randomStrategy = new RandomPlayStrategy();
        customQueueStrategy = new CustomQueueStrategy();
    }

public: 
    // geting the strategy instance
    static StrategyManager* getInstance() {
        if (!instance) {
            instance = new StrategyManager();
        }
        return instance;
    }

    // get strategy by name
    PlayStrategy* getStrategy(PlayStrategyType type) {
        if (type == PlayStrategyType::SEQUENTIAL) {
            return sequentialStrategy;
        } else if (type == PlayStrategyType::RANDOM) {
            return randomStrategy;
        } else if (type == PlayStrategyType::CUSTOM_QUEUE) {
            return customQueueStrategy;
        } else {
            throw runtime_error("Invalid strategy type.");
        }
    }
};


// Initialize the static instance pointer to nullptr
StrategyManager* StrategyManager::instance = nullptr;