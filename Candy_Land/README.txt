CandyLand

HOW TO COMPILE AND RUN:

Compile:
g++ -Werror -Wall -Wpedantic -std=c++17 Board.cpp Character.cpp Player.cpp BoardDriver.cpp -o cl

Run:
./cl

DEPENDENCIES:

The following files must be in the same directory as the .cpp files in order to compile:

Character.h, Player.h, Game.h, Board.h, results.txt, riddles.txt, characters.txt, candies.txt

DATE: Dec 7, 2023

ABOUT THIS PROJECT:

This project implements an interactive board game modeled after Candy Land.
Two players compete against each other to reach the castle, where the first to arrive is declared the winner.
