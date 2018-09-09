#ifndef LOCALGAMESCENE_H
#define LOCALGAMESCENE_H

#include "gamescene.h"
#include "healthybar.h"
#include"energybar.h"
#include"explodingitem.h"
#include"guiflyitem.h"
#include <QEvent>

class LocalGameScene : public GameScene
{
public:
    LocalGameScene();
    ~LocalGameScene();
protected:
    // 游戏线程
    void timerEvent(QTimerEvent *);

    bool event(QEvent *);



private:
    Player1P item1;
    Player2P item2;
    HealthyBar healthBar_1;
    HealthyBar healthBar_2;
    EnergyBar energyBar_1;
    EnergyBar energyBar_2;
    ExplodingItem m_explodingitem;

    // 游戏线程ID
    int timerId;
};

#endif // LOCALGAMESCENE_H
