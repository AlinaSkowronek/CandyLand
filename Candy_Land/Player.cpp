#include "Player.h"
#include "Character.h"
#include "Board.h"
#include <string>
#include <cstdlib> // need for the random function

Player::Player()
{
    _player_number = 0;
    _player_name = "";
    _character = Character();
    _current_board_position = -1;
    _playerGoesAgain = false;
    _playerLoosesTurnCount = 0;
}

Player::Player(int player_number, string player_name, Character character, int current_player_position, bool playerGoesAgain, int playerLoosesTurnCount)
{
    _player_number = player_number;
    _player_name = player_name;
    _character = character;
    _current_board_position = current_player_position;
    _playerLoosesTurnCount = playerLoosesTurnCount;
}
// getters
int Player::getplayerLoosesTurnCount() const
{
    return _playerLoosesTurnCount;
}
int Player::getPlayerNumber() const
{
    return _player_number;
}
string Player::getPlayerName() const
{
    return _player_name;
}
int Player::getCurrentBoardPosition() const
{
    return _current_board_position;
}

Character Player::getCharacter() const
{
    return _character;
}

bool Player::getplayerGoesAgain() const
{
    return _playerGoesAgain;
}

// setters
void Player::setplayerLoosesTurnCount(int playerLoosesTurnCount)
{
    _playerLoosesTurnCount = playerLoosesTurnCount;
}
void Player::setPlayerNumber(int player_number)
{
    _player_number = player_number;
}

void Player::setPlayerName(string player_name)
{
    _player_name = player_name;
}

void Player::setCurrentBoardPosition(int current_board_position)
{
    _current_board_position = current_board_position;
}

void Player::setCharacter(Character character)
{
    _character = character;
}

void Player::setplayerGoesAgain(bool playerGoesAgain)
{
    _playerGoesAgain = playerGoesAgain;
}

bool Player::compare(const Player &p) const
{
    bool result = false;

    if (_player_number == p.getPlayerNumber())
    {
        result = true;
    }

    return result;
}