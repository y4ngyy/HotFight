#ifndef LOCALGAMESCENE_H
#define LOCALGAMESCENE_H

#include "gamescene.h"
#include "healthybar.h"
#include"energybar.h"
#include"angerbar.h"
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
    Player1P m_item1;
    Player2P m_item2;
    HealthyBar m_healthBar_1;
    HealthyBar m_healthBar_2;
    EnergyBar m_energyBar_1;
    EnergyBar m_energyBar_2;
    AngerBar m_angerBar_1;
    AngerBar m_angerBar_2;
    ExplodingItem m_explodingitem;


    // 游戏线程ID
    int timerId;
};

#endif // LOCALGAMESCENE_H
