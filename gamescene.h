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

private:
    Player1P item1;
    Player2P item2;

    // 游戏线程ID
    int timerId;

    // scene大小
    QRectF size;
};


#endif // GAMESCENE_H
