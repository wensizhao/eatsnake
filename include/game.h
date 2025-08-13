#ifndef GAME 
#define GAME
#include<chrono>
#include "./food.h"
#include "./map.h"
#include"snake.h"
#include<thread>
using Clock=std::chrono::steady_clock;

enum  GameState{paused,running,over};


class game{
public:
    void gaStart();
    void gaBuild();
    void testfoodplace();
    bool isOpposite(Direction a,Direction b);
    void gaClear();
public:
    map m;
    food f;
    snake s;



};

#endif