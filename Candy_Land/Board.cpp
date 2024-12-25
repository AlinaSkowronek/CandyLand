#include "Board.h"
#include "Player.h"
#include "Character.h"
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <array>
#include <cstdlib> // need for the random function

Board::Board()
{
    resetBoard();
}

void Board::resetBoard()
{
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
    Tile new_tile;
    string current_color;
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        new_tile = {current_color, "regular tile"};
        _tiles[i] = new_tile;
    }

    // Add for special tiles

    // short cut tile
    Tile shortcut_tile = _tiles[18];
    shortcut_tile.tile_type = "special tile";
    shortcut_tile.special_type = "SHORTCUT";
    _tiles[18] = shortcut_tile;

    Tile shortcut_tile2 = _tiles[78];
    shortcut_tile2.tile_type = "special tile";
    shortcut_tile2.special_type = "SHORTCUT";
    _tiles[78] = shortcut_tile2;

    Tile shortcut_tile3 = _tiles[52];
    shortcut_tile3.tile_type = "special tile";
    shortcut_tile3.special_type = "SHORTCUT";
    _tiles[52] = shortcut_tile3;

    Tile shortcut_tile4 = _tiles[21];
    shortcut_tile4.tile_type = "special tile";
    shortcut_tile4.special_type = "SHORTCUT";
    _tiles[21] = shortcut_tile4;

    // Icecream stop tile
    Tile icecream_tile = _tiles[36];
    icecream_tile.tile_type = "special tile";
    icecream_tile.special_type = "ICEREAM";
    _tiles[36] = icecream_tile;

    // Gumdrop forrest tile
    Tile gumdrop_forest = _tiles[55];
    gumdrop_forest.tile_type = "special tile";
    gumdrop_forest.special_type = "GUMDROP";
    _tiles[55] = gumdrop_forest;

    Tile gumdrop_forest3 = _tiles[80];
    gumdrop_forest3.tile_type = "special tile";
    gumdrop_forest3.special_type = "GUMDROP";
    _tiles[80] = gumdrop_forest3;

    Tile gumdrop_forest4 = _tiles[73];
    gumdrop_forest4.tile_type = "special tile";
    gumdrop_forest4.special_type = "GUMDROP";
    _tiles[73] = gumdrop_forest4;

    // Gingerbread House Tile
    Tile gingerbread_house = _tiles[74];
    gingerbread_house.tile_type = "special tile";
    gingerbread_house.special_type = "GINGERBRED";
    _tiles[74] = gingerbread_house;

    Tile gingerbread_house2 = _tiles[9];
    gingerbread_house2.tile_type = "special tile";
    gingerbread_house2.special_type = "GINGERBRED";
    _tiles[9] = gingerbread_house2;

    Tile gingerbread_house3 = _tiles[49];
    gingerbread_house3.tile_type = "special tile";
    gingerbread_house3.special_type = "GINGERBRED";
    _tiles[49] = gingerbread_house3;

    // Hidden treausres
    Tile hidden_treasure1 = _tiles[24];
    hidden_treasure1.hasHiddenTreasure = true;
    _tiles[24] = hidden_treasure1;

    Tile hidden_treasure2 = _tiles[46];
    hidden_treasure2.hasHiddenTreasure = true;
    _tiles[46] = hidden_treasure2;

    Tile hidden_treasure3 = _tiles[63];
    hidden_treasure3.hasHiddenTreasure = true;
    _tiles[63] = hidden_treasure3;

    new_tile = {ORANGE, "regular tile"};
    _tiles[_BOARD_SIZE - 1] = new_tile;

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1;
    }

    // Set candy stores
    _candy_store_position[0] = -1;
    _candy_store_position[1] = 6;
    _candy_store_position[2] = 40;
    _candy_store_position[3] = 68;

    _player_position = 0;
    _player1_position = -1;
    _player2_position = -1;

    /*for (int i = 0; i < _BOARD_SIZE; i++)
    {
        cout << "tile: " << i << "; " << _tiles[i].tile_type << "; " << _tiles[i].special_type << endl;
    }*/

    // cout << "resetting board" << endl;
}

void Board::displayTile(int position)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";

    if (position == _player1_position)
    {
        cout << "1";
    }
    else if (position == _player2_position)
    {
        cout << "2";
    }
    else
    {
        cout << " ";
    }
    cout << " " << RESET;
}

void Board::displayBoard()
{
    // First horizontal segment
    for (int i = 0; i <= 23; i++)
    {
        displayTile(i);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        displayTile(i);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        displayTile(i);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

bool Board::setPlayerPosition(int new_position)
{
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _player_position = new_position;
        return true;
    }
    return false;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

int Board::getPlayerPosition(int player) const
{
    return _player_position;
}

bool Board::addCandyStore(int position)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _candy_store_position[_candy_store_count] = position;
    _candy_store_count++;
    return true;
}

bool Board::isPositionCandyStore(int board_position)
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if (_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

Player Board::specialTileHander(Player player, Tile tile, int move_start_position)
{

    if (tile.tile_type == "special tile")
    {
        // Handle Shortcut
        if (tile.special_type == "SHORTCUT")
        {
            cout << endl;
            cout << "You landed on a shortcut tile!" << endl;
            cout << endl;
            cout << "Leap forward by four tiles." << endl;
            // cout << "tile: "
            //<< "; " << tile.tile_type << "; " << tile.special_type << endl;
            player.setCurrentBoardPosition(player.getCurrentBoardPosition() + 4);
        }

        // Handle Ice Cream Stop

        if (tile.special_type == "ICEREAM")
        {
            cout << endl;
            cout << "You landed on an ice cream stop tile!" << endl;
            cout << endl;
            cout << "You can draw a card again." << endl;
            if (player.getPlayerNumber() == 1)
            {
                player.setPlayerNumber(2);
            }
            else
            {
                player.setPlayerNumber(1);
            }
        }

        // Handle Gumdrop Forest
        if (tile.special_type == "GUMDROP")
        {
            cout << endl;
            cout << "You landed on a gumdrop forest tile!" << endl;
            cout << endl;
            cout << "You are taken four tiles back and gold is stolen from you." << endl;
            cout << endl;
            // moves player back 4 spaces

            if (player.getCurrentBoardPosition() < 4)
            {
                player.setCurrentBoardPosition(-1);
            }
            else
            {
                player.setCurrentBoardPosition(player.getCurrentBoardPosition() - 4);
            }

            // take gold
            int current_gold = player.getCharacter().getGold();

            // cout << "Initial gold: " << current_gold << endl;

            int random_gold_number = genRandomNumber(6, 5);
            int new_gold = current_gold - random_gold_number;

            if (new_gold < 0)
            {
                new_gold = 0;
            }

            Character tmp_character = player.getCharacter();
            tmp_character.setGold(new_gold);
            player.setCharacter(tmp_character);

            player.getCharacter().setGold(new_gold);

            cout << "Your gold is now " << player.getCharacter().getGold() << endl;
        }

        // Handle Gingerbread House

        if (tile.special_type == "GINGERBRED")
        {
            cout << endl;
            cout << "You landed on a gingerbread house forest tile!" << endl;
            cout << endl;
            cout << "You'll be transported back to your previous position on the path." << endl;
            cout << endl;
            cout << "You'll lose one of your valuable immunity candies." << endl;

            player.setCurrentBoardPosition(move_start_position);

            Candy new_candy;
            bool hasImmunity = false;
            string immunity_candy;
            array<string, 9> player_candy_array = player.getCharacter().getCandies();
            // remove an immunity candy

            // check to see if there is an immunity candy in players inventory.
            for (int i = 0; i < player_candy_array.size(); i++)
            {
                cout << player_candy_array[i] << endl;
                if (player_candy_array[i] == "Bubblegum Blast" || player_candy_array[i] == "Sparkling Sapphire" || player_candy_array[i] == "Caramel Comet")
                {
                    hasImmunity = true;
                    immunity_candy = player_candy_array[i];
                    // if there is an immunity candy take it off player's inventory
                    if (hasImmunity == true)
                    {
                        for (int j = 0; j < player_candy_array.size(); j++)
                        {
                            if (immunity_candy == player_candy_array[j])
                            {
                                player_candy_array[i] = "";
                                break;
                            }
                        }
                    }
                }
            }

            /*cout << "Here is your updated candy inventory: " << endl;

            for (int i = 0; i < player_candy_array.size(); i++)
            {
                // cout << player.getCharacter().getCandies()[i] << endl;
                if (player_candy_array[i] != "")
                {
                    cout << "[" << player_candy_array[i] << "]    ";
                }

                Character tmp_char = player.getCharacter();
                tmp_char.setCandies(player_candy_array);
                player.setCharacter(tmp_char);
            }*/
        }
    }

    return player;
}

Player Board::movePlayer(Player player, Card card)
{
    bool doneMoving = false;
    Player other_player;
    Tile current_tile;
    bool skippedFirstMatch = false;
    int move_start_position = player.getCurrentBoardPosition();
    vector<Player> players;
    // cout << "Start position: " << move_start_position << endl;

    while (!doneMoving)
    {
        // Move the player's position one tile
        // cout << "Current position is " << player.getCurrentBoardPosition() << endl;

        player.setCurrentBoardPosition(player.getCurrentBoardPosition() + 1);

        // cout << "Updated current player position in Board " << player.getCurrentBoardPosition() << endl;

        current_tile = getTile(player.getCurrentBoardPosition());

        // cout << "Card Color is " << card.color << endl;

        if (current_tile.color == card.color)
        {
            // cout << "Current color " << current_tile.color << endl;

            // Handle a double move
            if (card.double_color == true && skippedFirstMatch == false)
            {
                // cout << "Skipping first match " << endl;
                skippedFirstMatch = true;
            }
            else
            {
                // cout << "Done moving" << endl;
                doneMoving = true;

                // Temp test harness
                /*Tile test_tile = _tiles[74];
                Player test_player = specialTileHander(player, test_tile, move_start_position);
                cout << "Test player after special tile hanlder: " << test_player.getCurrentBoardPosition() << endl;
                */

                player = specialTileHander(player, current_tile, move_start_position);
                // players = MarshmellowHailstorm(player, other_player);
                //  player = regularTileHander(player, other_player);
                //   player = regularTileHander(player, current_tile, move_start_position);
                //    cout << "Updated current player position in Board after special tile hanlder: " << player.getCurrentBoardPosition() << endl;
            }
        }

        // Update player positions for drawing the board
        if (player.getPlayerNumber() == 1)
        {
            _player1_position = player.getCurrentBoardPosition();
            // cout << "_player1_position position " << _player1_position << endl;
        }
        else
        {
            _player2_position = player.getCurrentBoardPosition();
            // cout << "_player2_position position " << _player2_position << endl;
        }

        // Check for castle tile
        if (player.getCurrentBoardPosition() >= _BOARD_SIZE)
        {
            doneMoving = true;
        }
    }

    return player;
}

void Board::printMenu()
{
    cout << "1. Draw a card" << endl;
    cout << "2. Use Candy" << endl;
    cout << "3. Show player stats" << endl;
}

vector<Card> Board::populateCards()
{
    vector<Card> new_cards;
    // create instances for each type of card
    Card MagentaCard = {MAGENTA, "You drew a Cotton Candy Magenta card. Your game piece advances to Magenta tile. Here's the updated trail", false}; // Magenta
    Card BlueCard = {BLUE, "You drew a Bubblegum Blue card. Your game piece advances to Blue tile. Here's the updated trail", false};                // Blue
    Card GreenCard = {GREEN, "You drew a Minty Green card. Your game piece advances to Green tile. Here's the updated trail", false};
    Card DoubleMagentaCard = {MAGENTA, "You drew a double Cotton Candy Magenta card. Your game piece advances two Magenta tile. Here's the updated trail", true};
    Card DoubleBlueCard = {BLUE, "You drew a double Bubblegum Blue card. Your game piece advances two Blue tile. Here's the updated trail", true};
    Card DoubleGreenCard = {GREEN, "You drew a double Minty Green card. Your game piece advances two Green tile. Here's the updated trail", true};

    new_cards.push_back(MagentaCard);
    new_cards.push_back(BlueCard);
    new_cards.push_back(GreenCard);
    new_cards.push_back(DoubleMagentaCard);
    new_cards.push_back(DoubleBlueCard);
    new_cards.push_back(DoubleGreenCard);

    // cout << "New_cards size is: " << new_cards.size() << endl;

    return new_cards;
}

Tile Board::getTile(int position)
{
    return _tiles[position];
}

Card Board::drawRandomCard(vector<Card> new_cards)
{
    int random = (rand() % 6);
    // cout << "Random number is " << random << endl;

    return new_cards.at(random);
}

int Board::genRandomNumber(int range, int offset)
{
    int random = offset + (rand() % range);
    // cout << "Offest: " << offset << "; Range: " << range << endl;
    // cout << "Random number is " << random << endl;

    return random;
}

bool Board::rockPaperScissors()
{
    char user_input;
    int userChoice;
    bool isTie = false;

    do
    {
        srand(time(NULL));
        int compChoice = (rand() % 3);
        // cout << "comp choice is " << compChoice << endl;

        cout << "Let's play rock, papper, scissors!" << endl;
        cout << endl;

        cout << "Enter r, p, or s" << endl;
        cin >> user_input;

        // check user validation
        while (user_input != 'r' && user_input != 'p' && user_input != 's')
        {
            cout << "That is not a valid input. Please enter r, p, or s." << endl;
            cin >> user_input;
        }

        // conver char to int

        // r = 0
        // p = 1
        // s = 2
        if (user_input == 'r')
        {
            userChoice = 0;
        }
        else if (user_input == 'p')
        {
            userChoice = 1;
        }
        else
        {
            userChoice = 2;
        }

        if (userChoice == compChoice)
        {
            cout << "Tie! Play again" << endl;
            isTie = true;
        }
        else
        {
            isTie = false;
            if (userChoice == 1 && compChoice == 0)
            {
                cout << "You win!" << endl;
                return true;
                break;
            }
            else if (userChoice == 2 && compChoice == 1)
            {
                cout << "You win!" << endl;
                return true;
                break;
            }
            else if (userChoice == 2 && compChoice == 0)
            {
                cout << "You lost" << endl;
                return false;
                break;
            }
            else if (userChoice == 0 && compChoice == 1)
            {
                cout << "You lost." << endl;
                return false;
                break;
            }
            else if (userChoice == 1 && compChoice == 2)
            {
                cout << "You lost" << endl;
                return false;
                break;
            }
            else if (userChoice == 0 && compChoice == 2)
            {
                cout << "You win!" << endl;
                return true;
                break;
            }
        }
    } while (isTie == true);

    return false;
}

vector<Player> Board::regularTileHander(Player current_player, Player other_player)
{
    bool executeCalamity = false;

    int position = current_player.getCurrentBoardPosition();

    Tile tile = getTile(position);

    int random_number = genRandomNumber(100, 1);

    if (tile.tile_type == "regular tile")
    {

        if (random_number <= 40)
        {
            executeCalamity = true;
        }

        if (executeCalamity)
        {
            int number = genRandomNumber(100, 1);

            if (number <= 30)
            {
                // cout << "Candy Bandits!" << endl;
                cout << endl;
                cout << "Oh no! Candy Bandits have swiped your gold coins!" << endl;

                int current_gold = current_player.getCharacter().getGold();

                int random_gold_number = genRandomNumber(10, 1);
                int new_gold = current_gold - random_gold_number;

                if (new_gold < 0)
                {
                    new_gold = 0;
                }

                cout << random_gold_number << " was stolen from you!" << endl;

                Character tmp_character = current_player.getCharacter();
                tmp_character.setGold(new_gold);
                current_player.setCharacter(tmp_character);
            }
            else if (number <= 65)
            {
                // cout << "Lost in a Lollipop Labyrinth" << endl;
                cout << endl;
                cout << "Oh dear! You got lost in the lollipop labyrinth!" << endl;
                cout << endl;
                cout << "But you can recover the damage by playing Rock, Paper, Scissors." << endl;
                cout << "If you win, you get the lost turn back." << endl;

                bool wonRPS;

                wonRPS = rockPaperScissors();

                if (wonRPS == false)
                {
                    // Swap players
                    other_player.setplayerGoesAgain(true);
                    current_player.setplayerLoosesTurnCount(1);

                    // cout << "current player name is " << current_player.getPlayerName() << endl;
                    // cout << "current player loose count is " << current_player.getplayerLoosesTurnCount() << endl;
                }
            }
            else if (number <= 80)
            {
                // cout << "Candy Avalanche!" << endl;
                cout << endl;
                cout << "Watch out! A candy avalanche has struck!" << endl;
                cout << endl;
                cout << "But you can recover the damage by playing Rock, Paper, Scissors." << endl;
                cout << "If you win, you get the lost resources back." << endl;

                bool wonRPS;

                wonRPS = rockPaperScissors();

                if (wonRPS == false)
                {
                    // Skip current player's next turn
                    current_player.setplayerLoosesTurnCount(1);

                    // cout << "current player name is " << current_player.getPlayerName() << endl;
                    // cout << "current player loose count is " << current_player.getplayerLoosesTurnCount() << endl;

                    int current_stamina = current_player.getCharacter().getStamina();
                    int random_stamina_number = genRandomNumber(10, 5);
                    int new_stamina = current_stamina - random_stamina_number;

                    if (new_stamina < 0)
                    {
                        new_stamina = 0;
                    }

                    cout << "You lost " << random_stamina_number << " points of stamina." << endl;

                    Character tmp_character = current_player.getCharacter();
                    tmp_character.setGold(new_stamina);
                    current_player.setCharacter(tmp_character);
                }
                else
                {
                    current_player.setplayerLoosesTurnCount(1);
                }
            }
            else
            {
                // cout << "Sticky Taffy Trap" << endl;
                cout << endl;
                cout << "Oops! You are stuck in a sticky taffy trap!" << endl;

                array<string, 9> player_candy_array = current_player.getCharacter().getCandies();
                bool hasMagical = false;

                // Current Candies
                // cout << "Current Candies" << endl;
                // cout << endl;
                for (int i = 0; i < player_candy_array.size(); i++)
                {
                    // cout << player_candy_array[i] << endl;
                    if (player_candy_array[i] == "Frosty Fizz" || player_candy_array[i] == "Crimson Crystal" || player_candy_array[i] == "Mystic Marshmallow")
                    {
                        hasMagical = true;
                        cout << "You have a magical candy, which give you back your lost turn!" << endl;
                    }
                }

                if (hasMagical == false)
                {
                    current_player.setplayerLoosesTurnCount(1);
                }
            }
        }
    }

    vector<Player> updated_players;
    updated_players.push_back(current_player);
    updated_players.push_back(other_player);
    return updated_players;
}

vector<Player> Board::sameTileHandler(Player current_player, Player other_player)
{
    // cout << "START: sameTileHandler()" << endl;

    // Check for same tile
    // int current_player_number = current_player.getPlayerNumber();
    // Player other_player;
    vector<Player> same_tile_players;

    // cout << "Current player number is " << current_player_number << endl;
    // cout << "Current player's current gold is " << current_player.getCharacter().getGold() << endl;
    // cout << "Other player current position " << other_player.getCurrentBoardPosition() << endl;

    if (current_player.getCurrentBoardPosition() == other_player.getCurrentBoardPosition())
    {
        // cout << "Both players on same tile" << endl;
        array<string, 9> current_player_candies = current_player.getCharacter().getCandies();

        if (current_player.getCharacter().getHasSheild() == false)
        {
            cout << "Current player does not has sheild" << endl;
            int current_gold = current_player.getCharacter().getGold();
            // int random_gold_number = board.genRandomNumber(25, 5);
            int random_gold_number = genRandomNumber(25, 5);
            int new_gold = current_gold - random_gold_number;

            if (new_gold < 0)
            {
                new_gold = 0;
            }

            Character tmp_character = current_player.getCharacter();
            tmp_character.setGold(new_gold);
            current_player.setCharacter(tmp_character);

            other_player.setCurrentBoardPosition(other_player.getCurrentBoardPosition() - 1);
        }
    }

    // cout << "Other player's new position " << other_player.getCurrentBoardPosition() << endl;
    // cout << "Current player's new gold is " << current_player.getCharacter().getGold() << endl;

    same_tile_players.push_back(current_player);
    same_tile_players.push_back(other_player);

    return same_tile_players;
}

vector<riddle_answer> Board::loadRiddles(vector<riddle_answer> &riddles)
{
    // cout << "LOAD RIDDLES START" << endl;

    // read in character file;
    ifstream infile("riddles.txt");

    // check if file fails to open
    if (infile.fail())
    {
        cout << "Failed to open riddle file." << endl;
        return riddles;
    }

    string read_line;

    while (getline(infile, read_line))
    {
        stringstream ss(read_line);
        string riddle;
        string answer;

        getline(ss, riddle, '|');
        getline(ss, answer);

        riddle_answer new_riddle = {riddle, answer};
        riddles.push_back(new_riddle);
    }
    infile.close();

    // cout << "Riddle size is " << riddles.size() << endl;

    return riddles;
}

Player Board::hiddenTreasuresHandler(Player player)
{
    // cout << "HIDDEN TREASURE HANDLER START" << endl;

    Tile tile;
    vector<riddle_answer> riddles;

    tile = getTile(player.getCurrentBoardPosition());

    // cout << "Treasure is " << tile.hasHiddenTreasure << endl;

    // cout << "Position is " << player.getCurrentBoardPosition() << endl;

    if (tile.hasHiddenTreasure == true)
    {
        // generate random number between 1 and 20
        int random_number = genRandomNumber(19, 0);

        // choose a random riddle
        vector<riddle_answer> choose_riddle = loadRiddles(riddles);

        // riddle_answer chosen_riddle = choose_riddle.at(random_number);

        riddle_answer chosen_riddle = choose_riddle.at(random_number);

        cout << "Congratulations! You landed on a hidden treasure tile. Answer the riddle below correctly for a chance to win a treasure!" << endl;
        cout << endl;
        cout << endl;

        cout << "Riddle: " << chosen_riddle.riddles << endl;
        cout << endl;

        string user_answer;

        cout << "Answer: ";

        cin >> user_answer;

        if (user_answer != chosen_riddle.answers)
        {
            cout << "Your answer was incorrect, no treasures will be awarded." << endl;
            cout << endl;
        }

        if (user_answer == chosen_riddle.answers)
        {
            int random_treasure = genRandomNumber(100, 1);

            // cout << "random number generated : " << random_treasure << endl;

            if (random_treasure <= 30)
            {
                cout << "You recived a stamina refill." << endl;

                int current_stamina = player.getCharacter().getStamina();

                // cout << "Initial stamina: " << player.getCharacter().getStamina() << endl;

                // add random amount of stamina between 10-30
                int random_stamina_number = genRandomNumber(30, 10);

                // cout << "random stamina generated " << endl;

                int new_stamina = current_stamina + random_stamina_number;

                Character tmp_character = player.getCharacter();
                tmp_character.setStamina(new_stamina);
                player.setCharacter(tmp_character);

                // cout << "End stamina: " << player.getCharacter().getStamina() << endl;

                // if stamina is greater than 100, set to 100
                if (player.getCharacter().getStamina() > 100)
                {
                    player.getCharacter().setStamina(100);
                }
            }
            else if (random_treasure <= 40)
            {
                cout << "You recived a gold refill." << endl;

                int current_gold = player.getCharacter().getGold();

                // cout << "Initial gold: " << player.getCharacter().getGold() << endl;

                // add random amount of gold between 10-30
                int random_gold_number = genRandomNumber(40, 20);

                // cout << "random gold generated " << endl;

                int new_gold = current_gold + random_gold_number;

                Character tmp_character = player.getCharacter();
                tmp_character.setGold(new_gold);
                player.setCharacter(tmp_character);

                // if stamina is greater than 100, set to 100
                if (player.getCharacter().getGold() > 100)
                {
                    player.getCharacter().setGold(100);
                }

                // cout << "End gold: " << player.getCharacter().getGold() << endl;
            }
            else if (random_treasure <= 70)
            {
                cout << "You recived robber's repel." << endl;
                player.getCharacter().setHasSheild(true);
            }
            else
            {
                // cout << "You recived candy acquisition." << endl;

                int candy_acquisition = genRandomNumber(100, 1);

                // cout << "random number generated : " << candy_acquisition << endl;

                if (candy_acquisition <= 70)
                {
                    cout << "You recived jellybean of vigor, your stamina increased by 50 points" << endl;

                    int current_stamina = player.getCharacter().getStamina();

                    // cout << "Initial stamina: " << player.getCharacter().getStamina() << endl;

                    // cout << "random stamina generated " << endl;

                    int new_stamina = current_stamina + 50;

                    Character tmp_character = player.getCharacter();
                    tmp_character.setStamina(new_stamina);
                    player.setCharacter(tmp_character);

                    // if stamina is greater than 100, set to 100
                    if (player.getCharacter().getStamina() > 100)
                    {
                        player.getCharacter().setStamina(100);
                    }

                    // cout << "End stamina: " << player.getCharacter().getStamina() << endl;
                }
                else
                {
                    cout << "You recived treasure hunter's truffle." << endl;
                    cout << endl;
                    cout << "Solve another riddle to earn a prize" << endl;

                    hiddenTreasuresHandler(player);
                }
            }
        }
    }

    return player;
}

vector<Candy> Board::loadCandyAttributes()
{
    // cout << "LOAD CANDY ATTRIBUTES" << endl;
    vector<Candy> candyAttributes;
    ifstream infile("candies.txt");

    // check if file fails to open
    if (infile.fail())
    {
        cout << "Failed to open candy file." << endl;
        return candyAttributes;
    }

    string read_line;
    string word;
    getline(infile, word); // read the header line in the file

    while (getline(infile, read_line))
    {
        stringstream ss(read_line);
        string name;
        string description;
        string effectType;
        int effectValue;
        string stringEffectValue;
        string candyType;
        int price;
        string stringPrice;

        getline(ss, name, '|');
        getline(ss, description, '|');
        getline(ss, effectType, '|');
        getline(ss, stringEffectValue, '|');
        // cout << "stringEffectValue: " << stringEffectValue << endl;
        // effectValue = (int)stoi(stringEffectValue);

        effectValue = stoi(stringEffectValue);
        getline(ss, candyType, '|');
        getline(ss, stringPrice);
        price = stoi(stringPrice);

        Candy newCandy = {name, description, effectType, effectValue, candyType, price};
        // cout << "adding new candy" << endl;
        candyAttributes.push_back(newCandy);
    }
    infile.close();

    /*for (int i = 0; i < candyAttributes.size(); i++)
    {

        cout << candyAttributes[i].candy_name << endl;
        cout << candyAttributes[i].candy_description << endl;
        cout << candyAttributes[i].effect_Type << endl;
        cout << candyAttributes[i].effect_Value << endl;
        cout << candyAttributes[i].candy_Type << endl;
        cout << candyAttributes[i].candy_price << endl;
    }*/

    return candyAttributes;
}

vector<Candy> Board::displayCandyStore(vector<Candy> candyStoreCandies)
{

    int random_number1 = genRandomNumber(11, 0);
    int random_number2;
    int random_number3;
    bool isUnique = false;
    // cout << random_number1 << endl;

    while (!isUnique)
    {
        random_number2 = genRandomNumber(11, 0);

        if (random_number1 != random_number2)
        {
            isUnique = true;
        }
    }

    isUnique = false;

    while (!isUnique)
    {
        random_number3 = genRandomNumber(11, 0);

        if ((random_number1 != random_number3) && ((random_number2 != random_number3)))
        {
            isUnique = true;
        }
    }

    // vector<Candy> candyStoreCandies = loadCandyAttributes();

    cout << "Here is a list of candies in the candy store: " << endl;
    cout << endl;

    cout << "Name: " << candyStoreCandies.at(random_number1).candy_name << endl;
    cout << "Description: " << candyStoreCandies.at(random_number1).candy_description << endl;
    cout << "Effect: " << candyStoreCandies.at(random_number1).effect_Type << endl;
    cout << "Effect Value: " << candyStoreCandies.at(random_number1).effect_Value << endl;
    cout << "Candy Type: " << candyStoreCandies.at(random_number1).candy_Type << endl;
    cout << "Price: " << candyStoreCandies.at(random_number1).candy_price << endl;
    cout << "_______________________________________________________" << endl;

    cout << "Name: " << candyStoreCandies.at(random_number2).candy_name << endl;
    cout << "Description: " << candyStoreCandies.at(random_number2).candy_description << endl;
    cout << "Effect: " << candyStoreCandies.at(random_number2).effect_Type << endl;
    cout << "Effect Value: " << candyStoreCandies.at(random_number2).effect_Value << endl;
    cout << "Candy Type: " << candyStoreCandies.at(random_number2).candy_Type << endl;
    cout << "Price: " << candyStoreCandies.at(random_number2).candy_price << endl;
    cout << "_______________________________________________________" << endl;

    cout << "Name: " << candyStoreCandies.at(random_number3).candy_name << endl;
    cout << "Description: " << candyStoreCandies.at(random_number3).candy_description << endl;
    cout << "Effect: " << candyStoreCandies.at(random_number3).effect_Type << endl;
    cout << "Effect Value: " << candyStoreCandies.at(random_number3).effect_Value << endl;
    cout << "Candy Type: " << candyStoreCandies.at(random_number3).candy_Type << endl;
    cout << "Price: " << candyStoreCandies.at(random_number3).candy_price << endl;
    cout << "_______________________________________________________" << endl;

    return candyStoreCandies;
}

Player Board::playerChooseCandy(vector<Candy> candyStoreCandies, Player player)
{
    string user_candy_choice;
    bool validInput = false;
    char input;

    bool playGame;

    cout << "Would you like to play a game, for a chance to get 10 percent off on all candies? (y/n)" << endl;
    cin >> input;

    while (input != 'y' && input != 'n')
    {
        cout << "You did not enter a valid input. Please enter y or n." << endl;
        cin >> input;
    }

    if (input == 'y')
    {
        playGame = discountGame();
    }

    cout << "Which candy would you like to buy?" << endl;
    cout << endl;

    getline(cin >> ws, user_candy_choice);

    for (int i = 0; i < candyStoreCandies.size(); i++)
    {
        if (user_candy_choice == candyStoreCandies[i].candy_name)
        {
            validInput = true;
        }
    }

    // cout << "User input is " << user_candy_choice << endl;
    cout << endl;

    // VALIDATE INPUT
    while (validInput == false)
    {
        for (int i = 0; i < candyStoreCandies.size(); i++)
        {
            if (user_candy_choice == candyStoreCandies[i].candy_name)
            {
                validInput = true;
                break;
            }
            if (validInput == false)
            {
                cout << "Your input does not match one of the candies listed above. Please try again." << endl;
                getline(cin >> ws, user_candy_choice);
            }
        }
    }

    Candy new_candy;
    array<string, 9> player_candy_array = player.getCharacter().getCandies();

    // Current Candies
    /*cout << "Current Candies" << endl;
    cout << endl;
    for (int i = 0; i < player_candy_array.size(); i++)
    {
        cout << player_candy_array[i] << endl;
    }*/

    bool hasCapacity = false;

    // Check for capacity
    for (int i = 0; i < player_candy_array.size(); i++)
    {
        if (player_candy_array[i] == "")
        {
            hasCapacity = true;
            break;
        }
    }

    // Get the selected candy
    for (int i = 0; i < candyStoreCandies.size(); i++)
    {
        if (user_candy_choice == candyStoreCandies[i].candy_name)
        {
            new_candy = candyStoreCandies[i];
        }
    }

    cout << endl;
    // cout << "The selected new candy is " << new_candy.candy_name << endl;
    // cout << endl;

    // hasCapacity = false;

    if (hasCapacity)
    {
        // cout << "Has capacity" << endl;
        // cout << endl;

        // deduct gold
        if (player.getCharacter().getGold() >= new_candy.candy_price)
        {
            int current_gold = player.getCharacter().getGold();

            // cout << "Initial gold: " << current_gold << endl;

            int new_gold = current_gold - new_candy.candy_price;

            if (playGame == true)
            {
                new_gold = new_gold - (new_gold * 0.10);
            }
            else if (playGame == true)
            {
                new_gold = new_gold + (new_gold * 0.10);
            }

            Character tmp_character = player.getCharacter();
            tmp_character.setGold(new_gold);
            player.setCharacter(tmp_character);

            // cout << "End gold: " << player.getCharacter().getGold() << endl;

            for (int i = 0; i < player_candy_array.size(); i++)
            {
                if (player_candy_array[i] == "")
                {
                    // cout << "adding candy name: " << new_candy.candy_name << endl;
                    // cout << endl;
                    player_candy_array[i] = new_candy.candy_name;
                    break;
                }
            }
        }
        else
        {
            cout << "You do not have enough gold" << endl;
        }
    }
    else
    {
        char user_input;
        string candy_sub;
        cout << "You do not have sufficent place in the candy inventory. Would you like to subsitute your candy with an exisiting candy? (y/n)" << endl;
        cin >> user_input;

        // ADD VALIDATION

        while (user_input != 'y' && user_input != 'n')
        {
            cout << "You did not enter a valid input. Please enter y or n." << endl;
            cin >> user_input;
        }

        if (user_input == 'y')
        {
            cout << "Which candy would you like to subsitute?" << endl;
            getline(cin >> ws, candy_sub);

            // cout << "Candy sub is " << candy_sub << endl;

            int current_gold = player.getCharacter().getGold();

            // cout << "Initial gold: " << current_gold << endl;

            int new_gold = current_gold - new_candy.candy_price;

            Character tmp_character = player.getCharacter();
            tmp_character.setGold(new_gold);
            player.setCharacter(tmp_character);

            // cout << "End gold: " << player.getCharacter().getGold() << endl;

            for (int i = 0; i < player_candy_array.size(); i++)
            {
                if (candy_sub == player_candy_array[i])
                {
                    player_candy_array[i] = new_candy.candy_name;
                    break;
                }
            }

            cout << "Here is your updated candy inventory: " << endl;

            for (int i = 0; i < player_candy_array.size(); i++)
            {
                // cout << player.getCharacter().getCandies()[i] << endl;
                if (player_candy_array[i] != "")
                {
                    cout << "[" << player_candy_array[i] << "]    ";
                }
                else
                {
                    cout << "[Empty]";
                }

                // print two candies per row
                if ((i + 1) % 2 == 0)
                {
                    cout << endl;
                }
            }
            cout << endl;
        }
    }

    Character tmp_char = player.getCharacter();
    tmp_char.setCandies(player_candy_array);
    player.setCharacter(tmp_char);

    return player;
}

bool Board::isCandyPosition(int position)
{
    bool result = false;

    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        if (_candy_store_position[i] == position)
        {
            result = true;
            break;
        }
    }

    // cout << "Match is " << result << endl;

    return result;
}

vector<Player> Board::useCandy(Player current_player, Player other_player)
{
    vector<Player> the_players;
    string candy_choice;

    cout << "Here is a list of your candies: " << endl;

    for (int i = 0; i < current_player.getCharacter().getCandies().size(); i++)
    {
        // cout << player.getCharacter().getCandies()[i] << endl;
        if (current_player.getCharacter().getCandies()[i] != "")
        {
            cout << "[" << current_player.getCharacter().getCandies()[i] << "]    ";
        }

        // print two candies per row
        if ((i + 1) % 2 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;

    cout << "Enter a candy you wish to use:" << endl;
    getline(cin >> ws, candy_choice);

    // check if user input is valid
    bool candyFound = false;

    for (int i = 0; i < current_player.getCharacter().getCandies().size(); i++)
    {
        if (candy_choice == current_player.getCharacter().getCandies()[i])
        {
            candyFound = true;
            break;
        }
    }

    while (!candyFound)
    {
        cout << "You do not have " << candy_choice << " in your inventory." << endl;
        cout << endl;
        cout << "Please enter a candy that you currently have." << endl;
        getline(cin >> ws, candy_choice);

        for (int i = 0; i < current_player.getCharacter().getCandies().size(); i++)
        {
            if (candy_choice == current_player.getCharacter().getCandies()[i])
            {
                candyFound = true;
                break;
            }
        }
    }

    Candy candy_type = getCandy(candy_choice);
    bool candy_used = false;
    Character current_character = current_player.getCharacter();
    Character other_character = other_player.getCharacter();

    if (candy_type.candy_Type == "magical")
    {
        // cout << "MAGICAL CANDY CHOSEN!" << endl;
        if (candy_type.effect_Type == "stamina")
        {
            // cout << "initial stamina " << current_character.getStamina() << endl;

            int new_stamina = current_character.getStamina() + candy_type.effect_Value;
            current_character.setStamina(new_stamina);

            // cout << "end stamina " << current_character.getStamina() << endl;
            cout << "You have used " << candy_choice << " candy. This has increased your stamina by " << candy_type.effect_Value << " points." << endl;
            candy_used = true;
        }
    }
    else if (candy_type.candy_Type == "poison")
    {
        // bool hasImmunnity = false;
        bool canUse = false;

        // check if other player has immunity
        string immunity_candy;
        vector<Candy> find_immunity_candy = loadCandyAttributes();
        int immunity_candy_effect_value;

        // iterate through candy array
        for (int i = 0; i < other_character.getCandies().size(); i++)
        {
            int index = find_immunity_candy.size();

            // find a match from candy array
            for (int j = 0; j < index; j++)
            {
                if (other_character.getCandies()[i] == find_immunity_candy[j].candy_name)
                {
                    string tmp_candy = find_immunity_candy[j].candy_name;
                    // cout << "candy name is " << tmp_candy << endl;

                    // if names match, make sure candy is an immunity type
                    if (find_immunity_candy[j].candy_Type == "immunity")
                    {
                        // hasImmunnity = true;
                        immunity_candy = find_immunity_candy[j].candy_name;
                        immunity_candy_effect_value = find_immunity_candy[j].effect_Value;
                        if (candy_choice == "Lucky Licorice" || immunity_candy == "Bubblegum Blast")
                        {
                            canUse = true;
                            break;
                        }
                        else if ((candy_choice == "Lucky Licorice" || candy_choice == "Venomous Vortex") && (immunity_candy == "Sparkling Sapphire"))
                        {
                            canUse = true;
                            break;
                        }
                        else if ((candy_choice == "Lucky Licorice" || candy_choice == "Venomous Vortex" || candy_choice == "Toxic Taffy") && (immunity_candy == "Caramel Comet"))
                        {
                            canUse = true;
                            break;
                        }
                        else
                        {
                            canUse = false;
                            break;
                        }
                    }
                }
            }
        }

        // cout << "has immunity is " << hasImmunnity << endl;

        // if other player has an immunity candy
        if (canUse == true)
        {
            // cout << "initial stamina " << other_character.getStamina() << endl;

            // cout << "effect value is " << candy_type.effect_Value << endl;
            int new_stamina = other_character.getStamina() + candy_type.effect_Value + immunity_candy_effect_value;
            other_character.setStamina(new_stamina);

            // cout << "end stamina " << other_character.getStamina() << endl;

            cout << "You have used " << candy_choice << " but your opponent has " << immunity_candy << " candy to protect against your poison candy." << endl;
        }
        else
        {
            // cout << "initial stamina " << other_character.getStamina() << endl;

            // cout << "effect value is " << candy_type.effect_Value << endl;

            int new_stamina = other_character.getStamina() + candy_type.effect_Value;
            other_character.setStamina(new_stamina);

            // cout << "end stamina " << other_character.getStamina() << endl;
        }
        candy_used = true;
    }
    else if (candy_type.candy_Type == "gummy")
    {
        if (other_player.getPlayerNumber() == 1)
        {
            other_player.setPlayerNumber(2);
            current_player.setPlayerNumber(1);
            // cout << "Gummy player swap setting other player to 2: " << other_player.getPlayerNumber() << endl;
        }
        else
        {
            other_player.setPlayerNumber(1);
            current_player.setPlayerNumber(2);
            // cout << "Gummy player swap setting other player to 1: " << other_player.getPlayerNumber() << endl;
        }

        candy_used = true;
    }

    if (candy_used == true)
    {
        array<string, 9> updated_candies = current_character.getCandies();

        for (int i = 0; i < updated_candies.size(); i++)
        {
            if (updated_candies[i] == candy_type.candy_name)
            {
                updated_candies[i] = "";
            }
        }
        current_character.setCandies(updated_candies);
    }

    current_player.setCharacter(current_character);
    the_players.push_back(current_player);
    the_players.push_back(other_player);

    return the_players;
}

int Board::menuHandler()
{
    int user_choice;

    printMenu();

    cin >> user_choice;
    if (!cin)
    {
        cin.clear();
        cin.ignore(256, '\n');
    }

    // VALIDATE
    while (user_choice != 1 && user_choice != 2 && user_choice != 3)
    {
        cout << "You did not enter a valid option. Please enter 1, 2, or 3." << endl;
        cin >> user_choice;
    }

    return user_choice;
}

Candy Board::getCandy(string candy_name)
{
    vector<Candy> candy_list = loadCandyAttributes();
    Candy candy;

    for (int i = 0; i < candy_list.size(); i++)
    {
        if (candy_list[i].candy_name == candy_name)
        {
            candy = candy_list[i];
            break;
        }
    }

    return candy;
}

void Board::showPlayerStats(Player player)
{
    cout << "Here are your stats:" << endl;
    cout << endl;
    cout << "Player name: " << player.getPlayerName() << endl;
    cout << "Character: " << player.getCharacter().getName() << endl;
    cout << "Stamina: " << player.getCharacter().getStamina() << endl;
    cout << "Gold: " << player.getCharacter().getGold() << endl;
    cout << endl;
    cout << "Candies: " << endl;
    cout << endl;
    for (int i = 0; i < player.getCharacter().getCandies().size(); i++)
    {
        if (player.getCharacter().getCandies()[i] != "")
        {
            cout << "[" << player.getCharacter().getCandies()[i] << "]    ";
        }

        // print two candies per row
        if ((i + 1) % 2 == 0)
        {
            cout << endl;
        }
    }
}

vector<Player> Board::MarshmellowHailstorm(Player current_player, Player other_player)
{
    Tile tile;

    tile = getTile(current_player.getCurrentBoardPosition());

    int random_number = genRandomNumber(100, 1);

    if (random_number <= 5)
    {
        if (tile.tile_type == "regular tile" || tile.tile_type == "special tile")
        {
            int tiles_back = genRandomNumber(3, 1);

            cout << "Oh no, a Marshmallow Hailstorm!, both players get set back a few tiles." << endl;

            // cout << "Old position (current_player): " << current_player.getCurrentBoardPosition() << endl;
            // cout << "Old position (other_player): " << other_player.getCurrentBoardPosition() << endl;

            current_player.setCurrentBoardPosition(current_player.getCurrentBoardPosition() - tiles_back);

            // int old_position1 = current_player.getCurrentBoardPosition();
            // int new_position1 = old_position1 - tiles_back;

            other_player.setCurrentBoardPosition(other_player.getCurrentBoardPosition() - tiles_back);

            // cout << "New position (current_player): " << current_player.getCurrentBoardPosition() << endl;
            // cout << "New position (other_player): " << other_player.getCurrentBoardPosition() << endl;

            // int old_position2 = other_player.getCurrentBoardPosition();
            // int new_position2 = old_position2 - tiles_back;

            /*
            Player tmp_player;
            tmp_player.setCurrentBoardPosition(new_position1);
            current_player = tmp_player;

            Player tmp_player2;
            tmp_player2.setCurrentBoardPosition(new_position2);
            other_player = tmp_player2;
            */

            // player.getCharacter().setGold(new_gold);
        }
    }

    vector<Player> players;

    players.push_back(current_player);
    players.push_back(other_player);

    return players;
}

bool Board::discountGame()
{
    string scramble1 = "tewse";
    string word1 = "sweet";

    string scramble2 = "psiyc";
    string word2 = "spicy";

    string scramble3 = "ousr";
    string word3 = "sour";

    vector<string> scrambles;
    vector<string> words;

    scrambles.push_back(scramble1);
    scrambles.push_back(scramble2);
    scrambles.push_back(scramble3);

    words.push_back(word1);
    words.push_back(word2);
    words.push_back(word3);

    int random = genRandomNumber(2, 0);
    string answer;

    cout << "Unscramble this word" << endl;
    cout << endl;
    cout << scrambles.at(random);
    cout << endl;
    cin >> answer;
    cout << endl;

    if (random == 0 && answer == "sweet")
    {
        cout << "Correct!" << endl;
        return true;
    }
    else if (random == 1 && answer == "spicy")
    {
        cout << "Correct!" << endl;
        return true;
    }
    else if (random == 2 && answer == "sour")
    {
        cout << "Correct!" << endl;
        return true;
    }
    else
    {
        cout << "Sorry that is not right." << endl;
        return false;
    }
    cout << endl;
    return false;
}
