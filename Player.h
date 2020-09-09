#pragma once


class Player {

public:
    Player();

    void init(int dist_score, int obst_score);

    void setPosition(int x, int y);

    void getPosition(int &x, int &y);

    void jump();
    //void crouch();

private:
    //Properties
    int _dist_score;
    int _obst_score;

    //Position
    int _x;
    int _y;
};
