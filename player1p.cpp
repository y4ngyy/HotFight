#include "player1p.h"
#include <QPixmap>
#include <QKeyEvent>
#include <windows.h>

Player1P::Player1P()
{
    init_3();
    setHeight(p_standing.at(0).height());
}

/*
 * 1p控制方法 W D左右行走
 * J K分别为出拳和出腿
*/
void Player1P::keyPressEvent(QKeyEvent *event)
{
    // 技能释放中不处理键盘事件
    if(m_state != SKILL)
    {
        switch (event->key())
        {
            case Qt::Key_A:
                m_state = RUN;
                m_direction = LEFT;
                m_leftFlag = true;
                break;
            case Qt::Key_D:
                m_state = RUN;
                m_direction = RIGHT;
                m_rightFlag = true;
                break;
            case Qt::Key_J:
                if(m_attackClickFlag)
                {
                    m_state = PUNCH;
                    m_attackClickFlag = false;
                    // 添加进缓冲区
                    m_buffer.addKey('J');
                }
                break;
            case Qt::Key_K:
                if(m_attackClickFlag)
                {
                    m_state = KICK;
                    m_attackClickFlag = false;
                    // 添加进缓冲区
                    m_buffer.addKey('K');
                }
                break;
            case Qt::Key_I:
                m_state = SKILL;
                break;
            default:
                break;
        }
    }
}

void Player1P::keyReleaseEvent(QKeyEvent *event)
{
    // 技能释放中不处理键盘事件
    if(m_state != SKILL)
    {
        switch (event->key())
        {
            case Qt::Key_A:
                m_leftFlag = false;
                if(!m_leftFlag && !m_rightFlag)
                    m_state = STAND;
                break;
            case Qt::Key_D:
                m_rightFlag = false;
                if(!m_leftFlag && !m_rightFlag)
                    m_state = STAND;
                break;
            case Qt::Key_J:
            case Qt::Key_K:
                m_attackClickFlag = true;
                break;
            default:
                break;
        }
    }
}
