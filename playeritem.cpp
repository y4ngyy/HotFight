#include <QPainter>
#include "playeritem.h"
#include <QDebug>
#include <QImage>
#include <QTimer>

PlayerItem::PlayerItem()
{
    // 初始化变量
    m_state =  STAND;
    m_collidedState = NORMAL;

    standIndex = 0;
    runIndex = 0;
    punchIndex = 0;
    ishittingIndex = 0;
    kickIndex = 0;
}

PlayerItem::~PlayerItem()
{
}

void PlayerItem::init_1()
{
     p_standing.append(QPixmap(":/images/player1/standing.png"));
     p_running.append(QPixmap(":/images/player1/running_1.png"));
     p_running.append(QPixmap(":/images/player1/running_2.png"));
     p_running.append(QPixmap(":/images/player1/running_3.png"));
     p_running.append(QPixmap(":/images/player1/running_2.png"));
     p_punch.append(QPixmap(":/images/player1/punching_1.png"));
     p_punch.append(QPixmap(":/images/player1/punching_2.png"));
     p_punch.append(QPixmap(":/images/player1/punching_3.png"));
     p_punch.append(QPixmap(":/images/player1/punching_4.png"));
     p_ishitting.append(QPixmap(":/images/player1/ishitting_1.png"));
     p_ishitting.append(QPixmap(":/images/player1/ishitting_2.png"));
     p_ishitting.append(QPixmap(":/images/player1/ishitting_3.png"));
     p_kicking.append(QPixmap(":/images/player1/kicking_1.png"));
     p_kicking.append(QPixmap(":/images/player1/kicking_2.png"));
     p_kicking.append(QPixmap(":/images/player1/kicking_3.png"));
     p_kicking.append(QPixmap(":/images/player1/kicking_4.png"));
}


void PlayerItem::init_2()
{
        p_standing.append(QPixmap(":/images/player2/standing.png"));
        p_running.append(QPixmap(":/images/player2/running_1.png"));
        p_running.append(QPixmap(":/images/player2/running_2.png"));
        p_running.append(QPixmap(":/images/player2/running_3.png"));
        p_running.append(QPixmap(":/images/player2/running_4.png"));
        p_punch.append(QPixmap(":/images/player2/punching_1.png"));
        p_punch.append(QPixmap(":/images/player2/punching_2.png"));
        p_punch.append(QPixmap(":/images/player2/punching_3.png"));
        p_punch.append(QPixmap(":/images/player2/punching_3.png"));
        p_ishitting.append(QPixmap(":/images/player2/ishitting_1.png"));
        p_ishitting.append(QPixmap(":/images/player2/ishitting_2.png"));
        p_ishitting.append(QPixmap(":/images/player2/ishitting_3.png"));
        p_kicking.append(QPixmap(":/images/player2/kicking_1.png"));
        p_kicking.append(QPixmap(":/images/player2/kicking_2.png"));
        p_kicking.append(QPixmap(":/images/player2/kicking_3.png"));
        p_kicking.append(QPixmap(":/images/player2/kicking_4.png"));
}

void PlayerItem::init_3()
{
    p_standing.append(QPixmap(":/images/player3/standing_1.png"));
    p_standing.append(QPixmap(":/images/player3/standing_2.png"));
    p_standing.append(QPixmap(":/images/player3/standing_3.png"));
    p_standing.append(QPixmap(":/images/player3/standing_4.png"));
    p_standing.append(QPixmap(":/images/player3/standing_5.png"));
    p_standing.append(QPixmap(":/images/player3/standing_6.png"));
    p_standing.append(QPixmap(":/images/player3/standing_7.png"));
    p_standing.append(QPixmap(":/images/player3/standing_8.png"));
    p_standing.append(QPixmap(":/images/player3/standing_9.png"));
    p_standing.append(QPixmap(":/images/player3/standing_10.png"));
    p_standing.append(QPixmap(":/images/player3/standing_11.png"));
    p_standing.append(QPixmap(":/images/player3/standing_12.png"));
    p_standing.append(QPixmap(":/images/player3/standing_13.png"));
    p_running.append(QPixmap(":/images/player3/running_1.png"));
    p_running.append(QPixmap(":/images/player3/running_2.png"));
    p_running.append(QPixmap(":/images/player3/running_3.png"));
    p_running.append(QPixmap(":/images/player3/running_4.png"));
    p_running.append(QPixmap(":/images/player3/running_5.png"));
    p_running.append(QPixmap(":/images/player3/running_6.png"));
    p_running.append(QPixmap(":/images/player3/running_7.png"));
    p_punch.append(QPixmap(":/images/player3/punching_1.png"));
    p_punch.append(QPixmap(":/images/player3/punching_2.png"));
    p_punch.append(QPixmap(":/images/player3/punching_3.png"));
    p_punch.append(QPixmap(":/images/player3/punching_4.png"));
    p_punch.append(QPixmap(":/images/player3/punching_5.png"));
    p_punch.append(QPixmap(":/images/player3/punching_6.png"));
    p_punch.append(QPixmap(":/images/player3/punching_7.png"));
    p_punch.append(QPixmap(":/images/player3/punching_8.png"));
    p_punch.append(QPixmap(":/images/player3/punching_9.png"));
    p_kicking.append(QPixmap(":/images/player3/kicking_1.png"));
    p_kicking.append(QPixmap(":/images/player3/kicking_2.png"));
    p_kicking.append(QPixmap(":/images/player3/kicking_3.png"));
    p_kicking.append(QPixmap(":/images/player3/kicking_4.png"));
    p_kicking.append(QPixmap(":/images/player3/kicking_5.png"));
    p_kicking.append(QPixmap(":/images/player3/kicking_6.png"));
    p_kicking.append(QPixmap(":/images/player3/kicking_7.png"));
}

void PlayerItem::init_4()
{
    p_standing.append(QPixmap(":/images/player4/standing_1.png"));
    p_standing.append(QPixmap(":/images/player4/standing_2.png"));
    p_standing.append(QPixmap(":/images/player4/standing_3.png"));
    p_standing.append(QPixmap(":/images/player4/standing_4.png"));
    p_standing.append(QPixmap(":/images/player4/standing_5.png"));
    p_standing.append(QPixmap(":/images/player4/standing_6.png"));
    p_standing.append(QPixmap(":/images/player4/standing_7.png"));
    p_standing.append(QPixmap(":/images/player4/standing_8.png"));
    p_running.append(QPixmap(":/images/player4/running_1.png"));
    p_running.append(QPixmap(":/images/player4/running_2.png"));
    p_running.append(QPixmap(":/images/player4/running_3.png"));
    p_running.append(QPixmap(":/images/player4/running_4.png"));
    p_running.append(QPixmap(":/images/player4/running_5.png"));
    p_running.append(QPixmap(":/images/player4/running_6.png"));
    p_punch.append(QPixmap(":/images/player4/punching_1.png"));
    p_punch.append(QPixmap(":/images/player4/punching_2.png"));
    p_punch.append(QPixmap(":/images/player4/punching_3.png"));
    p_punch.append(QPixmap(":/images/player4/punching_4.png"));
    p_punch.append(QPixmap(":/images/player4/punching_5.png"));
    p_punch.append(QPixmap(":/images/player4/punching_6.png"));
    p_punch.append(QPixmap(":/images/player4/punching_7.png"));
    p_punch.append(QPixmap(":/images/player4/punching_8.png"));

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
            if(m_direction == RIGHT)
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
            if(standIndex == p_standing.size()-1)
            {
                standIndex = 0;
            }
            else
                standIndex++;
            if(m_direction == RIGHT)
            {
                painter->drawImage(0, 0, p_standing.at(standIndex).toImage());
            }
            else
                painter->drawImage(0, 0, p_standing.at(standIndex).toImage().mirrored(true,false));
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
            if(m_direction == RIGHT)
            {
                // drawPixmap 改为 drawImage 尝试修复图片拉长
                painter->drawImage(0, 0, p_punch.at(punchIndex).toImage());
            }
            else
            {
                painter->drawImage(0, 0, p_punch.at(punchIndex).toImage().mirrored(true,false));
            }
            break;
        case KICK:
            // 出脚视图 存在bug 图片显示不完全，且会留下边角图像
            if(kickIndex == p_kicking.size()-1)
            {
                kickIndex = 0;
                m_state = STAND;
            }
            else
                kickIndex++;

            // 左右方向显示
            if(m_direction == RIGHT)
            {
                painter->drawImage(0, 0, p_kicking.at(kickIndex).toImage());
            }
            else
            {
                painter->drawImage(0, 0, p_kicking.at(kickIndex).toImage().mirrored(true,false));
            }
            break;
        case ISHITTING:
            //受攻击视图
            if(ishittingIndex == p_ishitting.size()-1)
            {
                punchIndex = 0;
                m_state = STAND;       //被攻击的最后一帧应该停下来
                m_collidedState=NORMAL;
            }
            else
                ishittingIndex++;
            if(m_direction == RIGHT)
            {
                // drawPixmap 改为 drawImage 尝试修复图片拉长
                painter->drawImage(0, 0, p_ishitting.at(ishittingIndex).toImage());
            }
            else
            {
                painter->drawImage(0, 0, p_ishitting.at(ishittingIndex).toImage().mirrored(true,false));
            }
            break;
        default:
            break;
    }
}

QRectF PlayerItem::boundingRect() const
{
    // 将boundingRect改为较大定值区域 去除重绘bug
    // 要重写shape函数来作为碰撞检测的根据
    return QRectF(0, 0, 200, 200);
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
            m_width = p_standing.at(standIndex).width();
            m_height = p_standing.at(standIndex).height();
            break;
        case PUNCH:
            m_width = p_punch.at(punchIndex).width();
            m_height = p_punch.at(punchIndex).height();
            break;
        case ISHITTING:
            m_width = p_ishitting.at(ishittingIndex).width();
            m_width = p_ishitting.at(ishittingIndex).height();
            break;
        default:
            break;
    }
    // 同步速度变量
    m_speed = m_width/2;
}
    //所有的set/get函数的实现
void PlayerItem::setState(STATE t_state)
{
    m_state = t_state;
}

PlayerItem::STATE PlayerItem::getState()const
{
    return m_state;
}

void PlayerItem::setDirection(DIRECTION t_direction)
{
    m_direction = t_direction;
}

PlayerItem::DIRECTION PlayerItem::getDirection()const
{
    return m_direction;
}

void PlayerItem::setCollidedState(COLLIDEDSTATE t_collidedState)
{
    m_collidedState=t_collidedState;
}

PlayerItem::COLLIDEDSTATE PlayerItem::getCollidedState()const
{
    return m_collidedState;
}

void PlayerItem::setX(qreal x)
{
    m_x = x;
}

qreal PlayerItem::getX()const
{
    return m_x;
}

void PlayerItem::setY(qreal y)
{
    m_y = y;
}

qreal PlayerItem::getY()const
{
    return m_y;
}

void PlayerItem::setHeight(int t_height)
{
    m_height = t_height;
}

int PlayerItem::getHeight()const
{
    return m_height;
}

void PlayerItem::setWidth(int t_width)
{
    m_width = t_width;
}

int PlayerItem::getWidth()const
{
    return m_width;
}

void PlayerItem::setSpeed(int t_speed)
{
    m_speed = t_speed;
}

int PlayerItem::getSpeed()const
{
    return m_speed;
}

void PlayerItem::setBlood(int t_blood)
{
    m_blood = t_blood;
}

int  PlayerItem::getBlood()const
{
    return m_blood;
}

void PlayerItem::run()
{
    // 人物奔跑功能 m_x控制
    if(m_state != RUN || m_collidedState == ISATTACKED)  //如果人物僵直（ISATTACKED）也不能移动 （把原先的NORMAL更改为ISATTACKED）
        return;
    if( m_direction == LEFT && m_collidedState != ISCOLLIDEDLEFT)  //左边不能被挡住
    {
        m_x -= m_speed;
    }
    else if( m_direction == RIGHT && m_collidedState !=ISCOLLIDEDRIGHT)       //修改注释进行了更改
    {
        m_x += m_speed;
    }
    else
    {
        return;
    }
}

void PlayerItem::setPositonInfo(qreal x, qreal y)
{
    m_x = x;
    m_y = y;
}

void PlayerItem::updatePos()
{
    // 存在bug 改变图像大小的时候会导致view中残留未重绘部分
    prepareGeometryChange();
    setPixmapInfo();
    // 设置item在scene上的位置
    setPos(m_x, m_y);
}
