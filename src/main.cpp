// main.cpp
// Michael : started the game loop.

#include <iostream>
#include <exception>
#include "../include/GameManager.h"

int main() {
    try {
        // Initialize Game Instance Structure
        // NxN Grid limit, Victory Target Score setup.
        const int BOARD_DIMENSION = 5; 
        const int WIN_TARGET_SCORE = 150;
        
        GameManager engine(BOARD_DIMENSION, WIN_TARGET_SCORE);
        
        // Execute primary core loop
        engine.startGame();
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal Error in Game Structure: " << e.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "Unknown Critical Failure. Exiting.\n";
        return 1;
    }

    return 0;
}