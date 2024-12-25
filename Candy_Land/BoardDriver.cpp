
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstdlib> // need for the random function
#include <iostream>
#include "Board.h"
#include <string.h>
#include "Character.h"
#include "Player.h"

using namespace std;

void displayWelcome()
{
    cout << "Welcome to the game of candyland. " << endl;
    cout << endl;
}

Player createPlayer(vector<Character> character_list, string player1_character_name)
{
    Player new_player;
    string player_name;
    Character new_character;
    string player_selection;

    new_character = character_list.at(0);
    // new_player = {1, "Bob", new_character, 0};

    if (player1_character_name == "")
    {
        new_player.setPlayerNumber(1);
    }
    else
    {
        new_player.setPlayerNumber(2);
    }

    // Enter player name
    cout << "Enter player name: " << endl;
    cin >> player_name;
    cout << endl;
    new_player.setPlayerName(player_name);

    // Welcome screen
    cout << "Awsome! Here is a list of characters a player can select from: " << endl;
    cout << "______________________________________________" << endl;

    // display character menu
    new_character.displayCharacterSelection(character_list, player1_character_name);

    // have player1 input name of chosen character
    cout << endl;
    cout << "The selected character is" << endl;
    cin >> player_selection;
    cout << endl;

    // check that user selection is one of the characters
    while (player_selection != "JellyBean_Jane" && player_selection != "Toffee_Todd" && player_selection != "Chocolate_Charlie" && player_selection != "Caramel_Carl")
    {
        cout << "That is not one of the characters listed, please try again." << endl;
        cout << endl;
        cin >> player_selection;
        cout << endl;
    }

    for (int i = 0; i < character_list.size(); i++)
    {
        if (player_selection == character_list[i].getName())
        {
            new_player.setCharacter(character_list[i]);
            break;
        }
    }

    return new_player;
}

int main()
{
    vector<Character> characters;
    vector<Card> new_cards;
    Player player1;
    Player player2;
    bool gameOver = false;
    Player current_player;
    Tile special_tile;
    vector<riddle_answer> riddles;
    vector<Candy> candyAttributes;
    vector<Candy> candyStoreCandies;
    Player other_player;
    vector<Candy> candystore;
    vector<Player> the_players;

    // Provide a seed value for random numbers
    srand((unsigned)time(NULL));

    Character character;
    // load characters from file
    character.loadCharacters(characters);

    displayWelcome();

    player1 = createPlayer(characters, "");
    current_player = player1;
    // cout << "Player 1 Character:" << player1.getCharacter().getName() << endl;
    player2 = createPlayer(characters, player1.getCharacter().getName());
    // cout << "Player 2 Character:" << player2.getCharacter().getName() << endl;

    // print out board
    Board board;
    board.displayBoard();

    // Load candies from file
    candyAttributes = board.loadCandyAttributes();

    new_cards = board.populateCards();

    // candystore = board.displayCandyStore(candyStoreCandies);

    for (int i = 0; i < 2; i++)
    {
        if (board.isCandyPosition(current_player.getCurrentBoardPosition()))
        {
            char user_input;

            cout << current_player.getPlayerName() << " would you like to visit the candy store before the start of the game? (y/n)" << endl;
            cin >> user_input;

            // VALIDATE
            while (user_input != 'y' && user_input != 'n')
            {
                cout << "You did not enter a valid input. Please enter y or n." << endl;
                cin >> user_input;
            }

            if (user_input == 'y')
            {
                candystore = board.displayCandyStore(candyAttributes);
                current_player = board.playerChooseCandy(candystore, current_player);
            }
            current_player = player2;
            other_player = player1;
        }
    }

    // reset players to orginal numbers
    current_player = player1;
    other_player = player2;

    while (!gameOver)
    {
        // Check who each player is
        int current_player_number = current_player.getPlayerNumber();

        /*
        cout << "current player name " << current_player.getPlayerName() << endl;
        cout << "current player number is " << current_player.getPlayerNumber() << endl;
        cout << "current player loss count " << current_player.getplayerLoosesTurnCount() << endl;
        */

        if (current_player.getplayerLoosesTurnCount() > 0)
        {
            // cout << "Reverse swap" << endl;

            current_player.setplayerLoosesTurnCount(current_player.getplayerLoosesTurnCount() - 1);

            if (current_player_number == 1)
            {
                // cout << "setting other player to player one" << endl;
                player1 = current_player;
                other_player = player1;
                current_player = player2;
            }
            else
            {
                // cout << "setting other player to player 2" << endl;
                player2 = current_player;
                other_player = player2;
                current_player = player1;
            }
        }
        else
        {
            // cout << "normal player set" << endl;
            if (current_player_number == 1)
            {
                other_player = player2;
            }
            else
            {
                other_player = player1;
            }
        }

        cout << endl;
        cout << "It's " << current_player.getPlayerName() << " turn!" << endl;

        // menu handler
        int menu_choice = board.menuHandler();

        // VALIDATE
        bool show_menu_again = false;

        if (menu_choice == 1)
        {
            char user_input = toupper('d');
            cout << "To draw a card press D" << endl;
            cin >> user_input;
            show_menu_again = false;

            while (user_input != 'd' && user_input != 'D')
            {
                cout << "You did not enter a valid option. Please try again." << endl;
                cin >> user_input;
            }

            Card card_chosen = board.drawRandomCard(new_cards);
            // cout card message
            cout << card_chosen.message << endl;

            // Move current player
            // cout << "Current player position in driver " << current_player.getCurrentBoardPosition() << endl;
            current_player = board.movePlayer(current_player, card_chosen);
            board.displayBoard();
            cout << endl;
        }
        else if (menu_choice == 2)
        {
            // Use candy
            the_players = board.useCandy(current_player, other_player);

            // reset players to orginal numbers
            current_player = the_players.at(0);
            other_player = the_players.at(1);

            // cout << "Current player number " << current_player.getPlayerNumber() << endl;
            // cout << "Other player number " << other_player.getPlayerNumber() << endl;

            show_menu_again = false;
        }
        else if (menu_choice == 3)
        {
            // Show stats
            board.showPlayerStats(current_player);
            show_menu_again = true;
        }
        else
        {
            cout << "You did not enter one of the choices listed above. Please enter 1, 2, or 3" << endl;
            show_menu_again = true;
        }
        while (show_menu_again == true)
        {
            int menu_choice = board.menuHandler();

            if (menu_choice == 1)
            {
                char user_input = toupper('d');
                cout << "To draw a card press D" << endl;
                cin >> user_input;
                show_menu_again = false;

                while (user_input != 'd' && user_input != 'D')
                {
                    cout << "You did not enter a valid option. Please try again." << endl;
                    cin >> user_input;
                }

                Card card_chosen = board.drawRandomCard(new_cards);
                // cout card message
                cout << card_chosen.message << endl;

                // Move current player
                // cout << "Current player position in driver " << current_player.getCurrentBoardPosition() << endl;
                current_player = board.movePlayer(current_player, card_chosen);
                board.displayBoard();
            }
            else if (menu_choice == 2)
            {
                // Use candy
                the_players = board.useCandy(current_player, other_player);

                // reset players to orginal numbers
                current_player = the_players.at(0);
                other_player = the_players.at(1);
                show_menu_again = false;

                // cout << "Current player number " << current_player.getPlayerNumber() << endl;
                // cout << "Other player number " << other_player.getPlayerNumber() << endl;
            }
            else if (menu_choice == 3)
            {
                // Show stats
                board.showPlayerStats(current_player);
                show_menu_again = true;
            }
            else
            {
                cout << "You did not enter one of the choices listed above. Please enter 1, 2, or 3" << endl;
                show_menu_again = true;
            }
        }

        // Instead of redrawing a random card,  add menu choice !!!!!!!!!!!!

        // Card card_chosen = board.drawRandomCard(new_cards);
        // cout card message
        // cout << card_chosen.message << endl;

        // Move current player
        // cout << "Current player position in driver " << current_player.getCurrentBoardPosition() << endl;
        // current_player = board.movePlayer(current_player, card_chosen);
        // cout << "Updated player position in driver " << current_player.getCurrentBoardPosition() << endl;

        // load for riddles

        // check for riddles

        // Temp test harness
        /*Player test_player = current_player;
        Player test_player2 = other_player;
        test_player.setCurrentBoardPosition(5);
        test_player = board.MarshmellowHailstorm(test_player, test_player2);
        cout << "Test player after hidden Treasures hanlder: " << test_player.getCurrentBoardPosition() << endl;*/

        current_player = board.hiddenTreasuresHandler(current_player);

        // Check for candy store
        if (board.isCandyPosition(current_player.getCurrentBoardPosition()))
        {
            char user_input;

            cout << "You landed on a tile which has a candy store." << endl;
            cout << endl;

            cout << "Do you want to visit the candy store (y/n)" << endl;
            cin >> user_input;

            // VALIDATE
            while (user_input != 'y' && user_input != 'n')
            {
                cout << "You did not enter a valid input. Please enter y or n." << endl;
                cin >> user_input;
            }

            if (user_input == 'y')
            {
                candystore = board.displayCandyStore(candyAttributes);
                current_player = board.playerChooseCandy(candystore, current_player);
            }
            // Move code here
        }

        // Check for calamity
        the_players = board.regularTileHander(current_player, other_player);

        // reset players to orginal numbers
        current_player = the_players.at(0);
        other_player = the_players.at(1);

        // Check for same tile
        the_players = board.sameTileHandler(current_player, other_player);

        // reset players to orginal numbers
        current_player = the_players.at(0);
        other_player = the_players.at(1);

        the_players = board.MarshmellowHailstorm(current_player, other_player);

        // board.displayBoard();

        // Check if current player won the game
        if (current_player.getCurrentBoardPosition() >= board.getBoardSize() || other_player.getCurrentBoardPosition() >= board.getBoardSize())
        {
            gameOver = true;
            cout << current_player.getPlayerName() << " won!" << endl;

            // display player stats

            board.showPlayerStats(current_player);

            // load into results file
            ofstream outfile("results.txt");

            outfile << current_player.getPlayerName();
            outfile << "    ";
            outfile << current_player.getCharacter().getName();
            outfile << "    ";
            outfile << current_player.getCharacter().getGold();
            outfile << "    ";
            outfile << current_player.getCharacter().getStamina();
            outfile << "    ";

            for (int i = 0; i < current_player.getCharacter().getCandies().size(); i++)
            {
                if (current_player.getCharacter().getCandies()[i] != "")
                {
                    outfile << current_player.getCharacter().getCandies()[i];
                }
            }
            outfile << endl;
            return 0;
        }

        // Update current player

        // cout << "Starting normal swap" << endl;
        if (current_player.compare(player1))
        {

            player1 = current_player;
            current_player = player2;
            // cout << "Player 1 is current player" << endl;

            /*if (current_player.getplayerLoosesTurnCount() > 0)
            {
                cout << "current player becomes player 2" << endl;

                current_player.setplayerLoosesTurnCount(current_player.getplayerLoosesTurnCount() - 1);
                current_player = player2;

                cout << "Other player looses turn" << endl;
            }
            else
            {
                current_player = player2;
                cout << "Other player is now current player" << endl;
            }*/
        }
        else
        {
            player2 = current_player;
            current_player = player1;
            // cout << "Player 2 is current player" << endl;

            /*if (other_player.getplayerLoosesTurnCount() > 0)
            {
                other_player.setplayerLoosesTurnCount(other_player.getplayerLoosesTurnCount() - 1);

                cout << "Other player looses turn" << endl;
            }
            else
            {
                current_player = player1;
                cout << "Other player is now current player" << endl;
            }*/
        }

        // who is the current player
        // cout << "Switched players: " << current_player.getPlayerName() << endl;
        // cout << "Current player position in driver x2:  " << current_player.getCurrentBoardPosition() << endl;
        // gameOver = true;
    }

    /*
     */

    return 0;
}
