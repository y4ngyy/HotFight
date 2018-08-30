#ifndef PLAYER1P_H
#define PLAYER1P_H

#include "playeritem.h"

class Player1P : public PlayerItem
{
public:
    Player1P();
protected:
    // 继承父类虚函数 加载资源
    void loadResource();

    // 重写1P键盘操作
//    void keyPressEvent(QKeyEvent *);
//    void keyReleaseEvent(QKeyEvent *);

    // 无冲键盘操作
    void keyBoardListener();
private:

};

#endif // PLAYER1P_H
