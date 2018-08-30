#include "gamescene.h"
#include <QDebug>

GameScene::GameScene()
{
    addItem(&item1);
    addItem(&item2);
    timerId = startTimer(50);
}

void GameScene::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timerId)
    {
        qDebug() << item1.collidesWithItem(&item2);
    }
}
/*
 * 可以用来解决多item的事件分发
 * 但使用了新的键盘方案
 */
//bool GameScene::event(QEvent *event)
//{
//    switch(event->type())

//    {
//      case QEvent::KeyPress :        //如果是鼠标按下的事件
//            this->sendEvent(&item1,event);
//            this->sendEvent(&item2,event);
//            return true;
//            break;
//      case QEvent::KeyRelease :           //如果是鼠标松开时间
//           this->sendEvent(&item1,event);
//           this->sendEvent(&item2,event);
//           return true;
//           break;

//       default:
//            return QGraphicsScene::event(event);

//    }
//}



