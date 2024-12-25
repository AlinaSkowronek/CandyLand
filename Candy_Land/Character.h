#ifndef CHARACTER_H
#define CHARACTER_H

// class Player;
#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>

using namespace std;

class Character
{
private:
    string _name;
    int _stamina;
    int _gold;
    // vector<string> _candies;
    array<string, 9> _candies;
    bool _hasSheild = false;

public:
    Character(); // default constructor
    // paramaterized constructor                                                                                // default constructor
    Character(string name, int stamina, int gold, array<string, 9> candies);

    // getters
    string getName() const; // access character name
    int getStamina() const; // access character's stamina
    int getGold() const;    // access character's gold
    // vector<string> getCandies() const; // access character's candies
    array<string, 9> getCandies() const; // access character's candies
    bool getHasSheild() const;

    // setters
    void setName(string name);
    void setStamina(int stamina);
    void setGold(int gold);
    // void setCandies(vector<string> candies);

    void setCandies(array<string, 9> candies);

    void setHasSheild(bool);

    void loadCharacters(vector<Character> &characters);
    // load charcters from txt file

    void displayCharacterSelection(vector<Character> &characters, string player1_character_name);
    // print out menu that players can select a character from
};

#endif