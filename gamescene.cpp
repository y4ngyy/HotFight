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
    //增加skilll
     if( !(attackingitem.getState()==PlayerItem::PUNCH || attackingitem.getState()==PlayerItem::KICK
             ||attackingitem.getState()==PlayerItem::SKILL))
     {
         return false;
     }
     else
     {
         if( ! attackingitem.collidesWithItem( &attackeditem2 ) )  //如果没有检测到碰撞 预留接口（判断是否有远程攻击）
         {
             attackingitem.setCollidedState(PlayerItem::NOCOLLIDED);  //碰撞状态设成无碰撞
             attackeditem2.setCollidedState(PlayerItem::NOCOLLIDED);
             return false;
         }
         else
         {
             if( attackingitem.getDirection()==PlayerItem::LEFT          //判断人物朝向并且，判断人物的坐标
                     && attackingitem.getX()>= attackeditem2.getX())
             {
                if(attackeditem2.getTenacity()==0)
                {
                    //设置被攻击状态为硬直状态,如果硬直条清零的话进入硬直状态，任何键盘的输入都无效
                    attackeditem2.setAttackedState(PlayerItem::ISATTACKED);

                }
                 attackeditem2.setState(PlayerItem::ISHITTING);  //item2 被攻击

                Rule::calculateBlood(attackingitem,attackeditem2);//do something 计算伤害的预留接口
                if(attackeditem2.getAttackedState()!=PlayerItem::ISATTACKED)
                {
                    //在硬直状态下不能削韧
                    Rule::calculateTenacity(attackingitem,attackeditem2); //计算削韧//do something 计算伤害的预留接口
                }
                // 设置碰撞状态
                attackingitem.setCollidedState(PlayerItem::ISCOLLIDEDLEFT);
                attackeditem2.setCollidedState(PlayerItem::ISCOLLIDEDRIGHT);
                return true;
             }
             else if( attackingitem.getDirection()==PlayerItem::RIGHT          //判断人物朝向并且，判断人物的坐标
                      && attackingitem.getX()<= attackeditem2.getX())
             {
                 if(attackeditem2.getTenacity()==0)
                 {
                     //如果硬直条清零的话进入硬直状态，任何键盘的输入都无效
                     attackeditem2.setAttackedState(PlayerItem::ISATTACKED);

                 }
                  attackeditem2.setState(PlayerItem::ISHITTING);

                Rule::calculateBlood(attackingitem,attackeditem2);//do something 计算伤害的预留接口
                if(attackeditem2.getAttackedState()!=PlayerItem::ISATTACKED)
                {
                    //在硬直状态下不能削韧
                    Rule::calculateTenacity(attackingitem,attackeditem2); //计算削韧//do something 计算伤害的预留接口
                }
                // 设置碰撞状态
                attackingitem.setCollidedState(PlayerItem::ISCOLLIDEDRIGHT);
                attackeditem2.setCollidedState(PlayerItem::ISCOLLIDEDLEFT);
                return true;
             }
             else
             {
                return false;
             }
         }
     }
}

int GameScene::isCollided( PlayerItem& originalItem1, PlayerItem& targetItem2)
{
    if(!originalItem1.collidesWithItem(&targetItem2) )  //如果没有检测到碰撞,item1和item2的collidedstate均为正常，反会1
    {
        originalItem1.setCollidedState(PlayerItem::NOCOLLIDED);
        targetItem2.setCollidedState(PlayerItem::NOCOLLIDED);
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

