#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

Level::Level(){
    
}

void Level::load(string fileName, Player &player) {

    //Loads level
    ifstream file;

    file.open(fileName);
    if (file.fail()) {
        perror(fileName.c_str());
        system("PAUSE");
        exit(1);
    }

    string line;

    while (getline(file, line)) {
        _levelData.push_back(line);
    }

    file.close();

    char cell;
    //Process lvl
    for (int i = 0; i < _levelData.size(); i++) {
        for (int j = 0; j < _levelData[i].size(); j++) {
            cell = _levelData[i][j];

            switch(cell) {
                case '@':
                    player.setPosition(j, i);
                break;
            }
        }
    }

}

void Level::print() {

    cout << string(100, '\n');

    for (int i = 0; i < _levelData.size(); i++) {
        printf("%s\n", _levelData[i].c_str());
    }
    printf("\n");
}

void Level::movePlayer(char input, Player &player) {
    switch (input) {
        case (' ')://jump
        case ('w'):
        case ('W'):
            if (canJump(player)) {
                jump(player);
            }
            break;
        case ('s')://crouch
        case ('S'):
            printf("function not yet implemented");
            //_player.crouch();
        default:
            printf("INVALID INPUT");
            break;
    }
}

char Level::getCell(int x, int y) {
    char cell = _levelData[y][x];
    return cell;
}

void Level::setCell(int x, int y, char cell) {
    _levelData[y][x] = cell;
}

void Level::jump(Player &player) {

    int currentY;
    int currentX;
    player.getPosition(currentX,currentY);

    player.setPosition(currentX, currentY - 1);
    setCell(currentX, currentY - 1, '@');
    setCell(currentX, currentY, '.');
}

bool Level::canJump(Player &player) {
    int currentY;
    int currentX;
    player.getPosition(currentX, currentY);

    if (getCell(currentX, currentY + 1) != '#') {
        return false;
    } else {
        return true;
    }
}
