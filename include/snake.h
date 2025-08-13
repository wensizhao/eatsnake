#ifndef SNAKE 
#define SNAKE
#include<vector>
#include <utility>
#include"./food.h"
#include "./map.h"


enum  Direction{UP,DOWN,LEFT,RIGHT};

class snake{
public:
    std::vector<std::pair<int,int>> body;
    Direction dir;

    snake(int startX=1,int startY=1);

    void move();
    void eat();
    bool isHitwall();
    bool isHitself();
    bool isOccupy(int x,int y);
};


#endif