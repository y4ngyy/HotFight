#ifndef PLAYER1P_H
#define PLAYER1P_H

#include "playeritem.h"
#include <QKeyEvent>

class Player1P : public PlayerItem
{
public:
    Player1P();
    //用来判定攻击帧的函数
    virtual void JudgeingAttack();
protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

};

#endif // PLAYER1P_H
