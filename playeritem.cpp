#include <QPainter>
#include "playeritem.h"
#include <QDebug>
#include <QImage>
#include <QTimer>

PlayerItem::PlayerItem()
{
    // 初始化变量
    m_state =  STAND;
    runIndex = 0;
    punchIndex = 0;
}

PlayerItem::~PlayerItem()
{
}
void PlayerItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    switch (m_state)
    {
        case RUN:
            // 奔跑视图
            // 轮播下标增加
            if(runIndex == p_running.size()-1)
            {
                runIndex = 0;
            }
            else
                runIndex++;

            // 左右方向显示
            if(m_direction == LEFT)
            {
                painter->drawPixmap(0, 0, m_width, m_height, p_running.at(runIndex));
            }
            else
            {
                painter->drawImage(0, 0, p_running.at(runIndex).toImage().mirrored(true,false));
            }
                break;
        case STAND:
            // 站立状态视图
            if(m_direction == LEFT)
            {
                painter->drawImage(0, 0, p_standing.toImage());
            }
            else
                painter->drawImage(0, 0, p_standing.toImage().mirrored(true,false));
            break;
        case PUNCH:
            // 出拳视图
            if(punchIndex == p_punch.size()-1)
            {
                punchIndex = 0;
                m_state = STAND;
            }
            else
                punchIndex++;
            if(m_direction == LEFT)
            {
                // drawPixmap 改为 drawImage 尝试修复图片拉长
                painter->drawImage(0, 0, p_punch.at(punchIndex).toImage());
            }
            else
            {
                painter->drawImage(0, 0, p_punch.at(punchIndex).toImage().mirrored(true,false));
            }
        break;
        default:
            break;
    }
}

QRectF PlayerItem::boundingRect() const
{
    return QRectF(0, 0, m_width, m_height);
}

void PlayerItem::setPixmapInfo()
{
    // 根据状态同步 宽高 信息
    switch (m_state)
    {
        case RUN:
            m_width = p_running.at(runIndex).width();
            m_height = p_running.at(runIndex).height();
            break;
        case STAND:
            m_width = p_standing.width();
            m_height = p_standing.height();
            break;
        case PUNCH:
            m_width = p_punch.at(punchIndex).width();
            m_height = p_punch.at(punchIndex).height();
            break;
        default:
            break;
    }
    // 同步速度变量
    m_speed = m_width/2;
}

void PlayerItem::run()
{
    // 人物奔跑功能 m_x控制
    if(m_state != RUN)
        return;
    if(runIndex == 1|| runIndex == 3)
        return;
    if(m_direction == LEFT)
    {
        m_x -= m_speed;
    }
    else
    {
        m_x += m_speed;
    }
}

void PlayerItem::setPositonInfo(qreal x, qreal y)
{
    m_x = x;
    m_y = y;
}

void PlayerItem::updatePos()
{
    setPixmapInfo();
    setPos(m_x, m_y);
    prepareGeometryChange();
}
