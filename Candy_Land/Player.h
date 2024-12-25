#ifndef PLAYER_H
#define PLAYER_H

// class Character;
#include <iostream>
#include <vector>
#include "Character.h"

using namespace std;

class Player
{
private:
    int _player_number;
    string _player_name;
    Character _character;
    int _current_board_position;
    bool _playerGoesAgain = false;
    int _playerLoosesTurnCount;

public:
    Player();
    Player(int, string, Character, int, bool, int);
    // getters
    int getPlayerNumber() const;
    string getPlayerName() const;
    int getCurrentBoardPosition() const;
    Character getCharacter() const;
    bool getplayerGoesAgain() const;
    int getplayerLoosesTurnCount() const;

    // setters
    void setPlayerNumber(int);
    void setPlayerName(string);
    void setCurrentBoardPosition(int);
    void setCharacter(Character);
    bool compare(const Player &p) const;
    void setplayerGoesAgain(bool);
    void setplayerLoosesTurnCount(int);
};

#endif