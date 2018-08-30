#include <QPainter>
#include "playeritem.h"
#include <QDebug>
#include <QImage>
#include <QTimer>

PlayerItem::PlayerItem()
{
    // 加载图片资源
    // 调试时再使用， 资源加载在子类中
//    p_running.append(QPixmap(":/images/running_1.png"));
//    p_running.append(QPixmap(":/images/running_2.png"));
//    p_running.append(QPixmap(":/images/running_3.png"));
//    p_running.append(QPixmap(":/images/running_2.png"));
//    p_punch.append(QPixmap(":/images/punch_1.png"));
//    p_punch.append(QPixmap(":/images/punch_2.png"));
//    p_punch.append(QPixmap(":/images/punch_3.png"));
//    p_punch.append(QPixmap(":/images/punch_4.png"));

    // 初始化变量
    m_state =  STAND;
    runIndex = 0;
    punchIndex = 0;
    m_x = 0;
    m_y = 0;
    m_width = p_standing.width();
    m_height = p_standing.height();
    m_speed = m_width/2;

    // 设置item可以获取焦点
    setFlag(QGraphicsItem::ItemIsFocusable,true);
    // 设置焦点
    setFocus();
    // 开启定时器
    timerId = startTimer(100);
}

PlayerItem::~PlayerItem()
{
    killTimer(timerId);
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
                painter->drawPixmap(m_x, m_y, m_width, m_height, p_running.at(runIndex));
            }
            else
            {
                painter->drawImage(m_x,m_y, p_running.at(runIndex).toImage().mirrored(true,false));
            }
                break;
        case STAND:
            // 站立状态视图
            if(m_direction == LEFT)
            {
                painter->drawImage(m_x, m_y, p_standing.toImage());
            }
            else
                painter->drawImage(m_x,m_y, p_standing.toImage().mirrored(true,false));
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
                painter->drawImage(m_x, m_y, p_punch.at(punchIndex).toImage());
            }
            else
            {
                painter->drawImage(m_x,m_y, p_punch.at(punchIndex).toImage().mirrored(true,false));
            }
        break;
        default:
            break;
    }
}

// 将被子类重写 调试时使用 否则注释掉
//void PlayerItem::keyPressEvent(QKeyEvent *event)
//{
//    switch (event->key())
//    {
//        case Qt::Key_A:
//            m_direction = LEFT;
//            m_state = RUN;
//        break;
//        case Qt::Key_W:
//        case Qt::Key_D:
//            m_direction =  RIGHT;
//            m_state = RUN;
//        break;
//        case Qt::Key_S:
//        default:
//            break;
//    }
//}

//void PlayerItem::keyReleaseEvent(QKeyEvent *event)
//{
//    switch (event->key())
//    {
//        case Qt::Key_A:
//            m_state = STAND;
//        break;
//        case Qt::Key_D:
//            m_state = STAND;
//        break;
//        case Qt::Key_J:
//            m_state = PUNCH;
//            break;
//        default:
//            break;
//    }
//}

QRectF PlayerItem::boundingRect() const
{
    return QRectF(m_x, m_y, m_width, m_height);
}

void PlayerItem::setInfo()
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

void PlayerItem::timerEvent(QTimerEvent *event)
{
    // 定时刷新视图，实现动画效果
    if(event->timerId() == timerId)
    {

        // 同步信息
        setInfo();
        run();
        prepareGeometryChange();
        event->accept();
    }
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
