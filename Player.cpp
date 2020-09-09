#include"Player.h"
#include <iostream>

using namespace std;

//Constructor, init pos to 000
Player::Player() {
    _x = 0;
    _y = 0;
}

//Initializes a Player
void Player::init(int dist_score, int obst_score) {
    _dist_score = dist_score;
    _obst_score = obst_score;
}

void Player::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

void Player::getPosition(int &x, int &y) {
    x = _x;
    y = _y;
}

