#include "../include/MathLogic.h"
#include "../include/AxiomBoard.h"

#include <random>
#include <vector>
#include <numeric>
#include <cstdlib>

using namespace std;

namespace MathLogic {

    bool isPrime(int number) {
        if (number < 2) return false;

        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }

    bool areTwinPrimes(int a, int b) {
        return isPrime(a) && isPrime(b) && abs(a - b) == 2;
    }

    int generateTileValue() {

        static random_device rd;
        static mt19937 generator(rd());

        vector<int> primeTiles = {
            2, 3, 5, 7, 11, 13, 17, 19
        };

        vector<int> weights = {
            10, 10, 9, 8, 6, 5, 3, 2
        };

        discrete_distribution<int> distribution(weights.begin(), weights.end());

        int randomIndex = distribution(generator);
        return primeTiles[randomIndex];
    }

    int calculateAdjacencyScore(const AxiomBoard& board, int x, int y, int placedValue) {

        int score = placedValue;

        for (int rowOffset = -1; rowOffset <= 1; ++rowOffset) {
            for (int colOffset = -1; colOffset <= 1; ++colOffset) {

                if (rowOffset == 0 && colOffset == 0) {
                    continue;
                }

                int neighborX = x + rowOffset;
                int neighborY = y + colOffset;

                int neighborValue = board.getTile(neighborX, neighborY);

                if (neighborValue <= 0) {
                    continue;
                }

                score += 5;

                bool isOrthogonal =
                    (abs(rowOffset) + abs(colOffset) == 1);

                if (isOrthogonal) {
                    score += 3;
                }

                if (neighborValue == placedValue) {
                    score += 10;
                }

                if (areTwinPrimes(placedValue, neighborValue)) {
                    score += 8;
                }

                if (isPrime(placedValue + neighborValue)) {
                    score += 7;
                }

                int commonFactor = gcd(placedValue, neighborValue);

                if (commonFactor > 1) {
                    score += commonFactor * 2;
                }
            }
        }

        return score;
    }

    bool checkWinCondition(const AxiomBoard& board, int targetScore, int p1Score, int p2Score) {

        if (p1Score >= targetScore || p2Score >= targetScore) {
            return true;
        }

        if (board.isFull()) {
            return true;
        }

        return false;
    }

} 