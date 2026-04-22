// MathLogic.cpp
// Michael : made this file structure.
// Next Person (Person 2), please add your math formulas here!

#include "../include/MathLogic.h"
#include "../include/AxiomBoard.h"
#include <iostream>

namespace MathLogic {

    int generateTileValue() {
        // Person 2: Put your random dice or math number code here!
        return 5; // Michael : made this placeholder so the game runs safely.
    }

    int calculateAdjacencyScore(const AxiomBoard& board, int x, int y, int placedValue) {
        // Person 2: Add up the score based on tiles around (x, y).
        return 10; // Michael : made this placeholder so the game runs safely.
    }

    bool checkWinCondition(const AxiomBoard& board, int targetScore, int p1Score, int p2Score) {
        // Person 2: Write how the game ends here.
        // Michael : made it end when someone hits the target score or board fills up for now.
        if (p1Score >= targetScore || p2Score >= targetScore) return true;
        
        return board.isFull();
    }

} // namespace MathLogic