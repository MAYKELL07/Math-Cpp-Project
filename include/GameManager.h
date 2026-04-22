#pragma once

#include <string>
#include <memory>
#include "AxiomBoard.h"
#include "MathLogic.h"

// Michael : defined the player's status structure
struct Player {
    std::string name;
    int score;
    bool isSystem; // true if playing against AI/System
};

// Michael : setup the game manager to operate turns
class GameManager {
public:
    // Sets up the game size and points needed to win
    GameManager(int boardSize = 5, int targetScore = 150);

    // Starts the main game loop
    void startGame();

private:
    std::unique_ptr<AxiomBoard> board_;
    Player p1_;
    Player p2_;
    int currentPlayerIndex_;
    int targetScore_;

    void executeTurn(Player& currentP);
    void playerInputTurn(Player& currentP);
    void systemAutoTurn(Player& currentP);
    void declareWinner();
};