#ifndef FIGHTSCENE_H
#define FIGHTSCENE_H
#include<QGraphicsScene>
#include"player1p.h"
#include"player2p.h"
#include<QEvent>
#include<QKeyEvent>

class FightScene: public QGraphicsScene
{
public:
    FightScene();
protected:
   bool event(QEvent *event); //重载事件分发器

private:
    Player1P item1;
    Player2P item2;
};

#endif // FIGHTSCENE_H
