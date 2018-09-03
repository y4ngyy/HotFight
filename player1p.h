#ifndef PLAYER1P_H
#define PLAYER1P_H

#include "playeritem.h"

class Player1P : public PlayerItem
{
public:
    Player1P();

    // 无冲键盘操作
    void keyBoardListener();

};

#endif // PLAYER1P_H
