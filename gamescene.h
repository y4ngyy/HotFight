#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <QGraphicsScene>
#include"playeritem.h"
#include "player1p.h"
#include "player2p.h"
#include <QEvent>
#include <QKeyEvent>
#include <QTimerEvent>
#include<QDebug>

class GameScene: public QGraphicsScene
{
public:
    GameScene();
    bool IsAttacked( PlayerItem &AttackItem, PlayerItem &AttcekedItem);
protected:
//   bool event(QEvent *event); //重载事件分发器

    // 游戏机制线程
    void timerEvent(QTimerEvent *);

private:
    Player1P item1;
    Player2P item2;

    // 游戏线程ID
    int timerId;
};


#endif // GAMESCENE_H
