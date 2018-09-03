#include "gamescene.h"
#include <QDebug>

GameScene::GameScene()
{
    size.setRect(0, 0, 700, 700);
    setSceneRect(size);
}

GameScene::~GameScene()
{
}
bool GameScene::isAttacked( PlayerItem& attackingitem, PlayerItem& attackeditem2) //判断攻击的函数判断item1对item2的攻击判定,并且设定item2的状态
{
     //如果不是出拳的话，这里预留接口，还要加上其他的动作，或者考虑把所有的与攻击相关的状态重新声明一个枚举常量
     // 增加kick
     if( attackingitem.getState()!=PlayerItem::PUNCH && attackingitem.getState()!=PlayerItem::KICK)
     {
         return false;
     }
     else
     {
         if( ! attackingitem.collidesWithItem( &attackeditem2 ) )  //如果没有检测到碰撞 预留接口（判断是否有远程攻击）
         {
             attackeditem2.setCollidedState( PlayerItem::NORMAL );   //没被对方碰撞，把状态设成正常
             return false;
         }
         else
         {
             if( attackingitem.getDirection()==PlayerItem::LEFT          //判断人物朝向并且，判断人物的坐标
                     && attackingitem.getX()>= attackeditem2.getX())
             {
                attackeditem2.setCollidedState(PlayerItem::ISATTACKED);
                attackeditem2.setState(PlayerItem::ISHITTING);  //item2 被攻击
                //do something 计算伤害的预留接口
                return true;
             }
             else if( attackingitem.getDirection()==PlayerItem::RIGHT          //判断人物朝向并且，判断人物的坐标
                      && attackingitem.getX()<= attackeditem2.getX())
             {
                attackeditem2.setCollidedState(PlayerItem::ISATTACKED);
                attackeditem2.setState(PlayerItem::ISHITTING);  //item2 被攻击
                //do something 计算伤害的预留接口
                return true;
             }
             else
             {
                attackeditem2.setCollidedState( PlayerItem::NORMAL );
                return false;
             }
         }
     }
}

int GameScene::isCollided( PlayerItem& originalItem1, PlayerItem& targetItem2)
{
    if(!originalItem1.collidesWithItem(&targetItem2) )  //如果没有检测到碰撞,item1和item2的collidedstate均为正常，反会1
    {
        originalItem1.setCollidedState(PlayerItem::NORMAL);
        targetItem2.setCollidedState(PlayerItem::NORMAL);
        return 1;
    }
    else                                              //检测到碰撞
    {
        if(originalItem1.getX() <= targetItem2.getX())   //如果item1在item2的左边
        {
           originalItem1.setCollidedState(PlayerItem::ISCOLLIDEDRIGHT);   //item1的右边被挡住
           targetItem2.setCollidedState(PlayerItem::ISCOLLIDEDLEFT);          //对应的item2的左边被挡住
           return 0;
        }
        else
        {
            originalItem1.setCollidedState(PlayerItem::ISCOLLIDEDLEFT);   //item1的右边被挡住
            targetItem2.setCollidedState(PlayerItem::ISCOLLIDEDRIGHT);          //对应的item2的左边被挡住
            return -1;
        }
    }

}

