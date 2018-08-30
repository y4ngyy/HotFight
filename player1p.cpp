#include "player1p.h"
#include <QPixmap>
#include <QKeyEvent>

Player1P::Player1P()
{
    loadResource();
}

void Player1P::loadResource()
{
    p_standing.load(":/images/player1/standing.png");
     p_running.append(QPixmap(":/images/player1/running_1.png"));
     p_running.append(QPixmap(":/images/player1/running_2.png"));
     p_running.append(QPixmap(":/images/player1/running_3.png"));
     p_running.append(QPixmap(":/images/player1/running_2.png"));
     p_punch.append(QPixmap(":/images/player1/punching_1.png"));
     p_punch.append(QPixmap(":/images/player1/punching_2.png"));
     p_punch.append(QPixmap(":/images/player1/punching_3.png"));
     p_punch.append(QPixmap(":/images/player1/punching_4.png"));
}
/*
 * 1p控制方法 W D左右行走
 * J K分别为出拳和出腿
*/
void Player1P::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_A:
            m_direction = LEFT;
            m_state = RUN;
        break;
        case Qt::Key_D:
            m_direction =  RIGHT;
            m_state = RUN;
        break;
        default:
            break;
    }
}

void Player1P::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_A:
            m_state = STAND;
        break;
        case Qt::Key_D:
            m_state = STAND;
        break;
        case Qt::Key_J:
            m_state = PUNCH;
            break;
        default:
            break;
    }
}


