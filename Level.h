#pragma once
#include <vector>
#include <string>
#include "Player.h"

using namespace std;

class Level {

public:
    Level();

    void load(string fileName, Player &player);
    void print();

    void movePlayer(char input  ,Player &player);
    bool canJump(Player &player);
    void jump(Player &player);

    //Getters and Setters
    char getCell(int x, int y);
    void setCell(int x, int y, char cell);

private:
    vector <string> _levelData;
};