#include "netplayeritem.h"
#include <windows.h>

NetPlayerItem::NetPlayerItem(CHARACTOR c)
{
    if(c == C1)
        init_1();
    else
        init_2();
}

// 玩家操作的键盘监听
void NetPlayerItem::keyBoardListener()
{
    if(m_collidedState != ISATTACKED)    //只有不是被攻击(处于硬直状态键盘的操作才是有效的）
    {
        if(m_state == PUNCH || m_state == KICK)
            return;
        if(GetAsyncKeyState(65))
        {
            m_state = RUN;
            m_direction = LEFT;
            key = "A";
        }
        if(GetAsyncKeyState(68))
        {
            m_state = RUN;
            m_direction = RIGHT;
            key = "D";
        }
        if(!GetAsyncKeyState(65)&&!GetAsyncKeyState(68))
            m_state = STAND;
        // 出拳出腿判定 两者不能状态重叠 出腿优先
        if(GetAsyncKeyState(74))
        {
            m_state = PUNCH;
            key = "J";
        }
        if(GetAsyncKeyState(75))
        {
            m_state = KICK;
            key = "K";
        }
    }
    else
    {
      key = "isAttacked";
      return;
    }
}

// 网络传输的键盘监听
void NetPlayerItem::NetKeyBoardListener()
{
    if(m_collidedState != ISATTACKED)    //只有不是被攻击(处于硬直状态键盘的操作才是有效的）
    {
        if(m_state == PUNCH || m_state == KICK)
            return;
        if(key == "A")
        {
            m_state = RUN;
            m_direction = LEFT;
        }
        if(key == "D")
        {
            m_state = RUN;
            m_direction = RIGHT;
        }
        if(!GetAsyncKeyState(65)&&!GetAsyncKeyState(68))
            m_state = STAND;
        // 出拳出腿判定 两者不能状态重叠 出腿优先
        if(key == "J")
        {
            m_state = PUNCH;

        }
        if(key == "K")
        {
            m_state = KICK;

        }
    }
    else
    {
      return;
    }
}

QString NetPlayerItem::getKey()const
{
    return key;
}

 void NetPlayerItem::setKey(const QString t_key)
{
    key=t_key;
}
