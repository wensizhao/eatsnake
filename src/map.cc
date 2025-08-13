#include "../include/map.h"
#include <ncurses.h>


int map::maxX=0;
int map::maxY=0;
map:: map(){
    //ncurses初始化
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr,TRUE);
    nodelay(stdscr,TRUE);
    //设置游戏界面色彩
    if(has_colors()){
        start_color();
        use_default_colors();
        init_pair(1,COLOR_GREEN,COLOR_GREEN);//蛇身的颜色
        init_pair(2,COLOR_RED,COLOR_RED);//蛇头的颜色
        init_pair(3,COLOR_YELLOW,COLOR_YELLOW);//食物的颜色
        init_pair(4,COLOR_WHITE,COLOR_WHITE);//背景白色
    }
    getmaxyx(stdscr, map::maxY, map::maxX);
}

void map::draw(){
    clear();

    for(int i=0;i<maxX;i++){
        mvprintw(0,i,"#");
        mvprintw(maxY-1,i,"#");
    }
    for(int i=0;i<maxY;i++){
        mvprintw(i,0,"#");
        mvprintw(i,maxX-1,"#");
    }//设置游戏区域
    refresh();
}


void map:: clearmap(){
    endwin();//程序关闭时收回终端
}