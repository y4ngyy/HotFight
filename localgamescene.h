#ifndef LOCALGAMESCENE_H
#define LOCALGAMESCENE_H

#include "gamescene.h"

class LocalGameScene : public GameScene
{
public:
    LocalGameScene();
    ~LocalGameScene();
protected:
    // 游戏线程
    void timerEvent(QTimerEvent *);
private:
    Player1P item1;
    Player2P item2;

    // 游戏线程ID
    int timerId;
};

#endif // LOCALGAMESCENE_H
