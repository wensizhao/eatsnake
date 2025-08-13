#include "../include/game.h"
#include<iostream>



void start_menu(){
    std::cout<<"--------欢迎进入贪吃蛇游戏--------"<<'\n';
    std::cout<<"--------1.开始游戏--------------"<<'\n';
    std::cout<<"--------2.退出游戏--------------"<<'\n';
    std::cout<<"--------3.个性化设置-------------"<<'\n';
    std::cout<<"游戏说明:------------------------"<<'\n';
    std::cout<<"按q/Q退出游戏,按p/P暂停游戏,按c/C恢复游戏"<<'\n';
    std::cout<<"按W(w)/S(s)/A(a)/D(d)控制贪吃蛇运动方向"<<'\n';
    std::cout<<"------------------------------------"<<'\n';
    std::cout<<"请选择操作(1-3)"<<'\n';
};

int main(){
    while(true){
        start_menu();
        char choice;
        std::cin>>choice;
        switch(choice){
            case '1':{
                game g;
                g.gaBuild();
                g.gaStart();
                g.gaClear();
                break;
            }
            case '2':{
                std::cout<<"游戏正在退出！";
                return 0;
            }
            case '3':{
                break;
            }
            default:{
                std::cout<<"操作无效，请重新输入！";
                break;
            }
        };

    }
}