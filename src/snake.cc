#include "../include/snake.h"
#include"../include/map.h"



snake:: snake(int startX,int startY){

    body.push_back({startX+3,startY});
    body.push_back({startX+2,startY});
    body.push_back({startX+1,startY});
    body.push_back({startX,startY});

    dir=RIGHT;

};

void snake::move(){
    std::pair<int,int> head=body[0];
    if(dir==UP) head.second--;
    else if(dir==DOWN) head.second++;
    else if(dir==RIGHT) head.first++;
    else if(dir==LEFT) head.first--;

    auto tail =body.back();
    mvaddch(tail.second,tail.first,' ');
    body.insert(body.begin(),head);
    body.pop_back();
}//移动

void snake::eat(){
    std::pair<int,int> head=body[0];
    if(dir==UP) head.second--;
    else if(dir==DOWN) head.second++;
    else if(dir==RIGHT) head.first++;
    else if(dir==LEFT) head.first--;

    body.insert(body.begin(),head);   

}//吃到食物后的行为

bool snake::isHitwall(){
    std::pair<int,int> head=body[0];
    if(head.first>=map::maxX-1||head.first<=1||head.second>=map::maxY-1||head.second<1)
        return true;
    else
        return false;
}//判断是否撞到边缘

bool snake::isHitself(){
    for(int i=1;i<body.size();i++){
        if(body[0]==body[i])
            return true;
    };
    return false;
}//判断是否撞到自己

bool snake::isOccupy(int x,int y) {
    for(int i=0;i<body.size();i++){
        if(body[i].first==x&&body[i].second==y)
            return true;
    }
    return false;
}