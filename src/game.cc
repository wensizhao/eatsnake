#include "../include/game.h"
#include "../include/map.h"
#include "../include/snake.h"
#include "../include/food.h"
#include <ncurses.h>
#define STEP_INTERVAL 0.1


void game:: gaStart(){
    GameState state=running;
    m.draw();//设置游戏区域
    testfoodplace();//检测初始化的蛇和食物会不会重合，重合则重新生成
    gaBuild();//彩色图形构建
    auto last_move=Clock::now();//计时
    Direction next_dir=s.dir;//表示下一步的方向
    while(state==running||state==paused){
        int ch;
        nodelay(stdscr, TRUE);
        while((ch=getch())!=ERR){
            if(state==running){
                if(ch=='w'||ch=='W'){
                    if(!isOpposite(s.dir, UP))
                        next_dir=UP;

                }
                else if(ch=='s'||ch=='S'){
                    //printw("%d",ch);
                    //refresh();
                    if(!isOpposite(s.dir, DOWN))
                        next_dir=DOWN;

                }
                else if(ch=='a'||ch=='A'){
                    if(!isOpposite(s.dir, LEFT))
                        next_dir=LEFT;
                }
                else if(ch=='d'||ch=='D'){
                    if(!isOpposite(s.dir, RIGHT))
                        next_dir=RIGHT;
                }
                else if(ch=='p'||ch=='P'){
                    state=paused;
                }
                else if(ch=='q'||ch=='Q'){
                    state=over;
                    return;

                }
            } 
            else if(state==paused){
                if(ch=='c'||ch=='C')
                    state=running;
                else if(ch=='q'||ch=='Q'){
                    state=over;
                    return;}
            }
        }

        if(state==running){
            auto now=Clock::now();
            std::chrono::duration<double> elapsed =now-last_move;
            //printw("time=%f\n",elapsed.count());
            //refresh();
            if(elapsed.count()>=STEP_INTERVAL){
                s.dir=next_dir;
                if(s.isHitself()||s.isHitwall()){
                    state=over;
                    return;
                }
                else if(s.isOccupy(f.x, f.y)){
                    s.eat();
                    f.newFood();
                    testfoodplace();
                }
                else {
                    s.move();
                    gaBuild();
                    refresh();
                }

                gaBuild();
                refresh();
                last_move=now;
                

            }
            napms(50);
        }
    }
    

};


void game::gaBuild(){
    //创造食物的图形
    attron(COLOR_PAIR(3));
    mvprintw(f.y,f.x," ");
    attroff(COLOR_PAIR(3));

    //创造蛇的图形
    for(int i=0;i<s.body.size();i++){
        if(i==0)
            attron(COLOR_PAIR(2));
        else
            attron(COLOR_PAIR(1));
        mvprintw(s.body[i].second,s.body[i].first," ");

        if(i==0)
            attroff(COLOR_PAIR(2));
        else
            attroff(COLOR_PAIR(1));
    }
}

void game::testfoodplace(){
    if(s.isOccupy(f.x,f.y)){
        do{
            f.x=rand()%map::maxX;
            f.y=rand()%map::maxY;
        }while(s.isOccupy(f.x,f.y));
    }
}

bool game::isOpposite(Direction a,Direction b){
    return  ((a==UP&&b==DOWN)||(a==DOWN&&b==UP) 
            || (a==LEFT&&b==RIGHT)|| (a==RIGHT&&b==LEFT));
}

void game::gaClear(){
    clear();
    refresh();

    
    m.clearmap();
    system("clear");





}