# Axiom Array: Quantum Grid (Math-Cpp-Project)

## 🚀 Next Steps: Instructions for Person 2 (Math & Logic)

Hi Person 2! Michael here. I've finished setting up the core Game Engine (Board logic, Player Turns, System loop). 

Your job is to hook your **mathematical formulas** into the game. I made it extremely simple where to put everything.

### Where to add your code:
All your work will go directly into **`src/MathLogic.cpp`**. 

I have created three empty functions for you there:
1. `generateTileValue()`: Write your virtual dice/randomization math here (e.g. prime number sequences) to drop tiles.
2. `calculateAdjacencyScore()`: Write your adjacency and efficiency point-multiplier formulas here. The board state and placement `(x, y)` are passed right to you!
3. `checkWinCondition()`: Fill in how players actually win (e.g. geometric sequences, target score limit).

### How to test:
You just need to compile and run the project from `src/main.cpp`. My `GameManager` engine will automatically call your functions in `MathLogic.cpp`. Have fun!