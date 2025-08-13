#include "../include/food.h"
#include "../include/map.h"


food::food(){
    newFood();
}

void food::newFood(){

    x=rand()%(map::maxX-2)+1;
    y=rand()%(map::maxY-2)+1;

}