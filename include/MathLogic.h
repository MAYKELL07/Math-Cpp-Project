#pragma once

#include <vector>

// Forward Declaration for AxiomBoard.
class AxiomBoard;

// Michael : made this block of code to organize the math stuff.
namespace MathLogic {

    // Person 2: This is your function to roll the dice/make a number.
    int generateTileValue();

    // Person 2: This is your function to calculate the score from nearby tiles.
    int calculateAdjacencyScore(const AxiomBoard& board, int x, int y, int placedValue);

    // Person 2: This is your function to check if someone won.
    bool checkWinCondition(const AxiomBoard& board, int targetScore, int p1Score, int p2Score);

} // namespace MathLogic