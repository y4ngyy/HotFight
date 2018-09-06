#include "bar.h"

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

}
