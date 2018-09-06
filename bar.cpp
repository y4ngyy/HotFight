#include "bar.h"
#include <QPainter>

Bar::Bar()
{
    // 初始化血条
    m_width = MAX_WIDTH;
    m_height = 30;
}

void Bar::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    painter->setBrush(QBrush(QColor("#FF0000")));
    painter->drawRoundRect(0,0,m_width,m_height);
}

QRectF Bar::boundingRect() const
{
    return QRectF(0,0,MAX_WIDTH, m_height);
}
