#include "player2p.h"
#include <windows.h>

Player2P::Player2P()
{
    init_4();
    setHeight(p_standing.at(0).height());
}

/*
 * 1p控制方法 ← →左右行走
 * 1 2分别为出拳和出腿
*/
void Player2P::keyPressEvent(QKeyEvent *event)
{
    if(m_state != SKILL &&m_attackedState!=ISATTACKED)
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
                    m_attackClickFlag = false;
                    if(getEnergy() < m_punchEnReduce)
                        return;
                    m_state = PUNCH;
                    m_buffer.addKey('J');
                }
                break;
            case Qt::Key_2:
                if(m_attackClickFlag)
                {

                    m_attackClickFlag = false;
                    if(getEnergy() < m_kickEnReduce)
                        return;
                    m_state = KICK;
                    m_buffer.addKey('K');
                }
                break;
            case Qt::Key_5:
                m_state = SKILL;
                break;
            default:
                break;
        }
    }
}

void Player2P::keyReleaseEvent(QKeyEvent *event)
{
    if(m_state != SKILL &&m_attackedState!=ISATTACKED)
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
}
