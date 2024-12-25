#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdlib> // need for the random function
#include <string.h>
#define RED "\033[;41m"               /* Red */
#define GREEN "\033[;42m"             /* Green */
#define BLUE "\033[;44m"              /* Blue */
#define MAGENTA "\033[;45m"           /* Magenta */
#define CYAN "\033[;46m"              /* Cyan */
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0)*/
#define RESET "\033[0m"
#include "Character.h"
#include "Player.h"

using namespace std;

struct Candy
{
    string candy_name;
    string candy_description;
    string effect_Type;
    int effect_Value;
    string candy_Type;
    int candy_price;
    // vector<string> _deck_of_cards;
};

struct Tile
{
    string color;
    string tile_type;
    string special_type = "";
    bool hasHiddenTreasure = false;
};

struct Card
{
    string color;
    string message;
    bool double_color;
};

struct riddle_answer
{
    string riddles;
    string answers;
};

class Board
{
private:
    const static int _BOARD_SIZE = 83;
    Tile _tiles[_BOARD_SIZE];
    const static int _MAX_CANDY_STORE = 4;
    int _candy_store_position[_MAX_CANDY_STORE];
    int _candy_store_count;
    int _player_position;
    int _player1_position = -1;
    int _player2_position = -1;

public:
    Board();

    void resetBoard();
    void displayTile(int);
    void displayBoard();

    bool setPlayerPosition(int);

    int getBoardSize() const;
    int getCandyStoreCount() const;
    int getPlayerPosition(int) const;

    bool addCandyStore(int);
    /*
    -> Only allow user to go to candy store when the land on a certain tile
    -> Display cavailable candies with name, costs, and effects
   */
    bool isPositionCandyStore(int);

    bool movePlayerOld(int player, int tile_to_move_forward);

    void printMenu();

    string cardMessage(int card_number);
    // collect messages for cards drawn

    string drawCard();
    // function to draw a card randmomly

    Tile getTile(int position);

    vector<Card> populateCards();

    Card drawRandomCard(vector<Card> new_cards);

    Player movePlayer(Player player, Card card);

    Player specialTileHander(Player player, Tile tile, int move_start_position);

    int genRandomNumber(int range, int offset);

    vector<Player> sameTileHandler(Player current_player, Player other_player);

    vector<riddle_answer> loadRiddles(vector<riddle_answer> &riddles);

    Player hiddenTreasuresHandler(Player player);

    vector<Candy> loadCandyAttributes();

    vector<Candy> displayCandyStore(vector<Candy> candyStoreCandies);

    Player playerChooseCandy(vector<Candy> candyStoreCandies, Player player);

    bool isCandyPosition(int position);

    vector<Player> useCandy(Player current_player, Player other_player);

    int menuHandler();

    Candy getCandy(string candy_name);

    vector<Player> regularTileHander(Player current_player, Player other_player);

    bool rockPaperScissors();

    void showPlayerStats(Player player);

    vector<Player> MarshmellowHailstorm(Player current_player, Player other_player);

    bool discountGame();
};

#endif