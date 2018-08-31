#include "player1p.h"
#include <QPixmap>
#include <QKeyEvent>
#include <windows.h>

Player1P::Player1P()
{
    init();
}

void Player1P::init()
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
     p_ishitting.append(QPixmap(":/images/player1/ishitting_1.png"));
     p_ishitting.append(QPixmap(":/images/player1/ishitting_2.png"));
     p_ishitting.append(QPixmap(":/images/player1/ishitting_3.png"));
}

/*
 * 1p控制方法 W D左右行走
 * J K分别为出拳和出腿
*/
void Player1P::keyBoardListener()
{
    if(m_collidedState != ISATTACKED)    //只有不是被攻击(处于硬直状态键盘的操作才是有效的）
      {
        if(m_state == PUNCH)
            return;
        if(GetAsyncKeyState(65))
        {
            m_state = RUN;
            m_direction = LEFT;
        }
        if(GetAsyncKeyState(68))
        {
            m_state = RUN;
            m_direction = RIGHT;
        }
        if(!GetAsyncKeyState(65)&&!GetAsyncKeyState(68))
            m_state = STAND;
        if(GetAsyncKeyState(74))
        {
            m_state = PUNCH;
        }
    }
    else
      return;
}

