#include "gamescene.h"

GameScene::GameScene()
{
    addItem(&item1);
    addItem(&item2);
}

bool GameScene::event(QEvent *event)
{
    switch(event->type())

    {
      case QEvent::KeyPress :        //如果是鼠标按下的事件
            this->sendEvent(&item1,event);
            this->sendEvent(&item2,event);
            return true;
            break;
      case QEvent::KeyRelease :           //如果是鼠标松开时间
           this->sendEvent(&item1,event);
           this->sendEvent(&item2,event);
           return true;
           break;

       default:
            return QGraphicsScene::event(event);

    }
}

