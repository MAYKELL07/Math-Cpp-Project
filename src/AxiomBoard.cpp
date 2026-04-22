#include "../include/AxiomBoard.h"

// Initialize the 2D vector array for the grid.
AxiomBoard::AxiomBoard(int size) : size_(size), grid_(size, std::vector<int>(size, 0)) {
    // 0 represents an empty tile on the board.
}

bool AxiomBoard::inBounds(int x, int y) const {
    return (x >= 0 && x < size_) && (y >= 0 && y < size_);
}

bool AxiomBoard::placeTile(int x, int y, int value) {
    if (!inBounds(x, y)) {
        std::cerr << "[-] Error: Placement out of bounds (" << x << ", " << y << ").\n";
        return false;
    }
    if (grid_[x][y] != 0) {
        std::cerr << "[-] Error: Tile (" << x << ", " << y << ") is already occupied.\n";
        return false;
    }

    grid_[x][y] = value;
    return true;
}

int AxiomBoard::getTile(int x, int y) const {
    if (!inBounds(x, y)) {
        return -1; // -1 to indicate invalid access (assuming game uses positive integers)
    }
    return grid_[x][y];
}

bool AxiomBoard::isFull() const {
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (grid_[i][j] == 0) return false;
        }
    }
    return true;
}

void AxiomBoard::displayBoard() const {
    std::cout << "\n=== Current Game Board State ===\n";
    std::cout << "    ";
    for (int j = 0; j < size_; ++j) {
        std::cout << "[" << j << "] ";
    }
    std::cout << "\n";

    for (int i = 0; i < size_; ++i) {
        std::cout << "[" << i << "] ";
        for (int j = 0; j < size_; ++j) {
            if (grid_[i][j] == 0) {
                std::cout << " .  ";
            } else {
                std::cout << std::setw(2) << grid_[i][j] << "  ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "================================\n\n";
}
