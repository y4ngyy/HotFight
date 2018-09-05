#include "player2p.h"
#include <windows.h>

Player2P::Player2P()
{
    init_4();
}

/*
 * 1p控制方法 ← →左右行走
 * 1 2分别为出拳和出腿
*/
void Player2P::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Left:
            m_state = RUN;
            m_direction = LEFT;
            m_leftFlag = true;
            break;
        case Qt::Key_Right:
            m_state = RUN;
            m_direction = RIGHT;
            m_rightFlag = true;
            break;
        case Qt::Key_1:
            if(m_attackClickFlag)
            {
                m_state = PUNCH;
                m_attackClickFlag = false;
                m_buffer.addKey('J');
            }
            break;
        case Qt::Key_2:
            if(m_attackClickFlag)
            {
                m_state = KICK;
                m_attackClickFlag = false;
                m_buffer.addKey('K');
            }
            break;
        case Qt::Key_5:
            break;
        default:
            break;
    }
}

void Player2P::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Left:
            m_leftFlag = false;
            if(!m_leftFlag && !m_rightFlag)
                m_state = STAND;
            break;
        case Qt::Key_Right:
            m_rightFlag = false;
            if(!m_leftFlag && !m_rightFlag)
                m_state = STAND;
            break;
        case Qt::Key_1:
        case Qt::Key_2:
            m_attackClickFlag = true;
            break;
        default:
            break;
    }
}
