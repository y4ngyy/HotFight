#include "player2p.h"

Player2P::Player2P()
{
  loadResource();
}

void Player2P::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Left:
            m_direction = LEFT;
            m_state = RUN;
        break;
        case Qt::Key_Up:
        case Qt::Key_Right:
            m_direction =  RIGHT;
            m_state = RUN;
        break;
        case Qt::Key_Down:
        default:
            break;
    }

}
void Player2P::keyReleaseEvent(QKeyEvent *event)
{

    switch (event->key())
    {
        case Qt::Key_Left:
            m_state = STAND;
        break;
        case Qt::Key_Right:
            m_state = STAND;
        break;
        case Qt::Key_1:
            m_state = PUNCH;
            break;
        default:
            break;
    }
}
 void Player2P::loadResource()
{
       p_standing.load(":/images/player2/standing.png");
        p_running.append(QPixmap(":/images/player2/running_1.png"));
        p_running.append(QPixmap(":/images/player2/running_2.png"));
        p_running.append(QPixmap(":/images/player2/running_3.png"));
        p_running.append(QPixmap(":/images/player2/running_4.png"));
        p_punch.append(QPixmap(":/images/player2/punching_1.png"));
        p_punch.append(QPixmap(":/images/player2/punching_2.png"));
        p_punch.append(QPixmap(":/images/player2/punching_3.png"));

}
