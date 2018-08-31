#include "gamescene.h"
#include <QDebug>

GameScene::GameScene()
{
    // 测试人物坐标分开站立
    size.setRect(0, 0, 700, 700);
    setSceneRect(size);
    // 初始化人物位置
    item1.setPositonInfo(50, 400);
    item2.setPositonInfo(600, 400);
    addItem(&item1);
    addItem(&item2);
    timerId = startTimer(100);
}

void GameScene::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timerId)
    {
        // 游戏线程 刷新视图和人物跑动 碰撞
        item1.run();
        item2.run();
        // 碰撞
        item1.keyBoardListener();
        item2.keyBoardListener();
        item1.updatePos();
        item2.updatePos();
    }
}



