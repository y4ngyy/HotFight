#ifndef PLAYER1P_H
#define PLAYER1P_H

#include "playeritem.h"

class Player1P : public PlayerItem
{
public:
    Player1P();

    // 无冲键盘操作
    void keyBoardListener();

protected:

    // 继承父类虚函数 加载资源
    void init();

};

#endif // PLAYER1P_H
