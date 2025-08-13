#ifndef MAP  
#define MAP  
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

//设置点
typedef struct{
    int x;
    int y;
}Point;

class map{
public:
    static int maxY,maxX;
    map();
    void draw();
    void clearmap();
    


};


#endif