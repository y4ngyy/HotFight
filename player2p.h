#ifndef PLAYERITEM2_H
#define PLAYERITEM2_H
#include<playeritem.h>

class Player2P:public PlayerItem    //继承基类
{
public:
   Player2P();

    // 无冲型键盘监听方案
    void keyBoardListener();
};

#endif // PLAYERITEM2_H
