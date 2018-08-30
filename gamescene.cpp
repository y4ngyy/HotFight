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
//      qDebug() << item1.collidesWithItem(&item2);
        if( IsAttacked(item1,item2))
        {
            if(item1.getState()==PlayerItem::ISATTCAKED)
                qDebug()<<"P1被攻击了";
        }
        else if(IsAttacked(item2,item1) )
        {
            if(item2.getState()==PlayerItem::ISATTCAKED)
                qDebug()<<"P1被攻击了";
        }
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
bool GameScene::IsAttacked( PlayerItem& attackItem, PlayerItem& attackedItem)
{
    if(attackItem.getState()!=PlayerItem::PUNCH )           //如果不出拳的话
    {
        return false;
    }
    else
     if(attackItem.collidesWithItem(&attackedItem))
     {
     {
       if( PlayerItem::LEFT==attackItem.getDirection())    //如果人物方向向左的话
       {
           if( attackItem.getX()>= attackedItem.getX() )
           {
               attackedItem.setState(PlayerItem::ISATTCAKED);
               return true;
           }
           else
               return false;
       }
       else if(PlayerItem::RIGHT==attackItem.getDirection())
       {
           if( attackItem.getX() <=attackedItem.getX())
           {
               attackedItem.setState(PlayerItem::ISATTCAKED);
               return true;
           }
           else
               return false;
       }
       else
           return false;            //例外情况
    }
     }
    else
       return false;
}



