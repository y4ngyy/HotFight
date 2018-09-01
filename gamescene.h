#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <QGraphicsScene>
#include "player1p.h"
#include "player2p.h"
#include <QEvent>
#include <QKeyEvent>
#include <QTimerEvent>

class GameScene: public QGraphicsScene
{
public:
    GameScene();
protected:
//   bool event(QEvent *event); //重载事件分发器

    // 游戏机制线程
    void timerEvent(QTimerEvent *);

    //与游戏规则有关的函数

    bool isAttacked( PlayerItem& attackingitem, PlayerItem& attackeditem2); //判断攻击的函数
    //判断1P和2P是否碰上，如果item1的左边被挡住就返回-1，右边被挡住返回0,没有被挡住返回1(同时该函数也能够设定item2的状态，但是返回的是Item1的）
    int isCollided( PlayerItem& originalItem1, PlayerItem& targetItem2);
private:
    Player1P item1;
    Player2P item2;

    // 游戏线程ID
    int timerId;

    // scene大小
    QRectF size;

};


#endif // GAMESCENE_H
