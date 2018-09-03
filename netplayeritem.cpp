#include "netplayeritem.h"
#include <windows.h>
#include <QJsonObject>
#include <QJsonDocument>

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
        }
        if(GetAsyncKeyState(68))
        {
            m_state = RUN;
            m_direction = RIGHT;
        }
        if(!GetAsyncKeyState(65)&&!GetAsyncKeyState(68))
        {
            m_state = STAND;
        }
        // 出拳出腿判定 两者不能状态重叠 出腿优先
        if(GetAsyncKeyState(74))
        {
            m_state = PUNCH;
        }
        if(GetAsyncKeyState(75))
        {
            m_state = KICK;
        }
    }
    else
    {
      return;
    }
}

// 网络传输

QByteArray NetPlayerItem::sendJSInfo()
{
    QJsonObject js;
    js.insert("m_x", getX());
    js.insert("m_y", getY());
    js.insert("m_state", getState());
    js.insert("m_direction", getDirection());
    js.insert("m_collided", getCollidedState());
    QByteArray array;
    QJsonDocument doc;
    doc.setObject(js);
    array = doc.toJson(QJsonDocument::Compact);
    return array;
}

void NetPlayerItem::setNetWorkInfo(QJsonObject a)
{
    setPositonInfo(a.take("m_x").toDouble(), a.take("m_y").toDouble());
    setState(static_cast<PlayerItem::STATE>(a.take("m_state").toInt()));
    setDirection(static_cast<PlayerItem::DIRECTION>(a.take("m_direction").toInt()));
    setCollidedState(static_cast<PlayerItem::COLLIDEDSTATE>(a.take("m_collided").toInt()));
}
