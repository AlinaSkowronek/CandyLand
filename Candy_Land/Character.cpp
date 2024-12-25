#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include "Character.h"
#include "Player.h"
#include "Board.h"
#include <cstdlib> // need for the random function

using namespace std;

Character::Character() // default constructor
{
    // intialize all elemts to empty and 0
    _name = "";
    _stamina = 0;
    _gold = 0;
    //_candies.clear();
    for (int i = 0; i < 9; ++i)
    {
        _candies[i] = "";
    }
}

// parametrized constructor
Character::Character(string name, int stamina, int gold, array<string, 9> candies)
{
    _name = name;
    _stamina = stamina;
    _gold = gold;
    for (int i = 0; i < 9; ++i)
    {
        _candies[i] = candies[i];
    }
}

// getters
string Character::getName() const // access character name
{
    return _name;
}
int Character::getStamina() const // access character's stamina
{
    return _stamina;
}
int Character::getGold() const // access character's gold
{
    return _gold;
}
array<string, 9> Character::getCandies() const // access character's candies
{
    return _candies;
}

bool Character::getHasSheild() const
{
    return _hasSheild;
}

// setters
void Character::setName(string name)
{
    _name = name;
}
void Character::setStamina(int stamina)
{
    _stamina = stamina;
}
void Character::setGold(int gold)
{
    _gold = gold;
}
void Character::setCandies(array<string, 9> candies)
{
    for (int i = 0; i < 9; ++i)
    {
        _candies[i] = candies[i];
    }
}

void Character::setHasSheild(bool hasSheild)
{
    _hasSheild = hasSheild;
}

// load character from given txt file
void Character::loadCharacters(vector<Character> &characters)
{
    // read in character file;
    ifstream infile("characters.txt");

    // check if file fails to open
    if (infile.fail())
    {
        cout << "Failed to open character file." << endl;
        return;
    }

    string word;
    getline(infile, word); // read the header line in the file

    string read_line;
    array<string, 9> candyArray;

    while (getline(infile, read_line))
    {
        stringstream ss(read_line);
        string character_name;
        int gold;
        string string_gold;
        int stamina;
        string string_stamina;
        string candies;

        getline(ss, character_name, '|');
        getline(ss, string_stamina, '|');
        stamina = stoi(string_stamina);
        getline(ss, string_gold, '|');
        gold = stoi(string_gold);

        getline(ss, candies);
        // cout << "Candies are: " << candies << endl;

        // convert vector to array

        stringstream s(candies);
        // cout << "S is: " << s << endl;
        string candy;

        int count = 0;

        while ((getline(s, candy, ',')))
        {
            // cout << "Candy in while loop is" << candy << endl;
            candyArray[count] = candy;
            count++;
        }

        /*cout << "Candy array after: " << endl;
        for (int i = 0; i < candyArray.size(); i++)
        {
            cout << "position: " << i << endl;
            cout << "candy: " << candyArray[i] << endl;
        }*/

        // creating a Character object
        Character new_character = {character_name, stamina, gold, candyArray};
        characters.push_back(new_character);

        /*for (int i = 0; i < characters.size(); i++)
        {
            // cout << characters[i].character_name << endl;
            // cout << characters[i].gold << endl;
            // cout << characters[i].stamina << endl;
            // cout << characters[i].candies << endl;
        }*/
    }
    infile.close();
}

//
void Character::displayCharacterSelection(vector<Character> &characters, string player1_character_name)
{
    // Display character menu
    for (int i = 0; i < characters.size(); i++)
    {
        if (characters[i]._name != player1_character_name)
        {
            cout << "Name: " << characters[i]._name << endl;
            cout << "Stamina: " << characters[i]._stamina << endl;
            cout << "Gold: " << characters[i]._gold << endl;
            cout << endl;
            cout << "Candies: " << endl;
            cout << endl;

            // print candies
            for (int j = 0; j < characters[i].getCandies().size(); j++)
            {
                if (characters[i]._candies[j] != "")
                {
                    cout << "[" << characters[i]._candies[j] << "]    ";
                }

                // print two candies per row
                if ((j + 1) % 2 == 0)
                {
                    cout << endl;
                }
            }

            cout << "______________________________________________" << endl;
        }
    }
}
