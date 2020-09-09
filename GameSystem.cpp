#include "GameSystem.h"
#include <iostream>
#include <conio.h>

using namespace std;

//Constructor sets up game
GameSystem::GameSystem(string levelFileName) {

    _player.init(0, 0);

    _level.load(levelFileName, _player);

    playGame();

    system("PAUSE");
}

void GameSystem::playGame() {

    bool isDone = false;

    while (isDone == false) {
        _level.print();
        inputListener();
    }
}

void GameSystem::inputListener() {
    char input;
    printf("Press [space] to jump!");

    input = _getch();
    
    if (input == 'q') {
        quitGame();
    } else {
        _level.movePlayer(input, _player);
    }
}

int GameSystem::quitGame() {
    return 0;
}