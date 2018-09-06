#include "localgamescene.h"
#include <QDebug>

LocalGameScene::LocalGameScene()
{
    // 设置Scene大小
    setSceneRect(0,0,600,442);
    // 初始化人物位置
    item1.setPositonInfo(200, 300);
    item2.setPositonInfo(500, 300);
    addItem(&item1);
    addItem(&item2);
    timerId = startTimer(100);

}

LocalGameScene::~LocalGameScene()
{
}

void LocalGameScene::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timerId)
    {
        //设想（还没实现，因为经测试这样做有点小问题）因为可能要经常判断1P和2P是否碰撞，所以在成员变量中添加一个bool型的成员变量来减少对碰撞检测函数的调用

       /* isCollided(item1,item2);*/   //1P 和2P的 碰撞检测，必须放在攻击检测的前面，否则ISATTACKED会被替换成 ISCOLLIDEDLEFT，以后可以考虑整合成一个大函数
        //人物的攻击判定  测试
        if(isAttacked(item1,item2))
            qDebug()<<"item2被攻击了！"<<item2.getState()<<endl;
        if(isAttacked(item2, item1))
             qDebug()<<"item1被攻击了！"<<item1.getState()<<endl;

        // 游戏线程 刷新视图和人物跑动 碰撞
        item1.run();
        item2.run();
        // 碰撞
        item1.updatePos();
        item2.updatePos();
    }
}

// 事件分发函数，同时控制两个item人物
bool LocalGameScene::event(QEvent *event)
{
    switch(event->type())
    {
        case QEvent::KeyPress:
            sendEvent(&item1, event);
            sendEvent(&item2, event);
            return true;
        case QEvent::KeyRelease:
            sendEvent(&item1, event);
            sendEvent(&item2, event);
            return true;
        default:
            return GameScene::event(event);
    }
}
