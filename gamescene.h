#ifndef GAMESCENE_H
#define GAMESCENE_H


#include<QGraphicsScene>
#include"player1p.h"
#include"player2p.h"
#include<QEvent>
#include<QKeyEvent>

class GameScene: public QGraphicsScene
{
public:
    GameScene();
protected:
   bool event(QEvent *event); //重载事件分发器

private:
    Player1P item1;
    Player2P item2;
};


#endif // GAMESCENE_H
