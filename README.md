# CandyLand
Author: Alina Skowronek  
Language: C++  
Project Type: Board Game Simulation

---

## Project Overview
This project implements an interactive board game inspired by Candy Land. Two players compete against each other to reach the castle, where the first to arrive is declared the winner.

---

## How to Compile & Run

### Compile
```bash
g++ -Werror -Wall -Wpedantic -std=c++17 Board.cpp Character.cpp Player.cpp BoardDriver.cpp -o cl
```
## Dependencies
Ensure the following files are present in your project directory:

- Character.h  
- Player.h  
- Game.h  
- Board.h  
- results.txt  
- riddles.txt  
- characters.txt  
- candies.txt

---

## Features
- Two-player interactive board game  
- Reads characters, candies, riddles, and results from external text files  
- Uses object-oriented design (Board, Player, Character, etc.)  
- Simple simulation of Candy Land mechanics  
- Outputs end-game results

---

## Use Cases
- Demonstrates object-oriented programming in C++  
- Example of handling external input files  
- Basis for expanding into a more complex game or adding a GUI  
- Good reference for C++ class design and game state management

---

## Design & Implementation Notes
- Modular class design: Board, Character, Player, Game  
- Game logic driven by external data files for easy updates  
- Follows C++17 standards and strict compiler flags  
- Command-line interface with text-based gameplay  
- Results written to results.txt

---

## How to Test
1. Compile using the command in the README.  
2. Run the program.  
3. Verify that all data files load correctly.  
4. Play through a full game.  
5. Check results.txt for the game summary.  
6. Modify text files to test different scenarios.

---

## License
Created by Alina Skowronek.  
Use allowed for learning and academic purposes. Redistribution or commercial use requires permission.

---

## Future Improvements
- Add a graphical user interface (GUI)  
- Add an AI opponent  
- Include animations or sound effects  
- Expand board layout and special tiles  
- Allow more than two players  
