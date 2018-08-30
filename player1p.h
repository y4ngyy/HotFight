#ifndef PLAYER1P_H
#define PLAYER1P_H

#include "playeritem.h"

class Player1P : public PlayerItem
{
public:
    Player1P();
protected:
    // 继承父类纯虚函数 加载资源
    void loadResource();

    // 重写1P键盘操作
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
private:

};

#endif // PLAYER1P_H
