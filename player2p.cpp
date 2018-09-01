#include "player2p.h"
#include <windows.h>

Player2P::Player2P()
{
    init();
}

void Player2P::init()
{
        p_standing.load(":/images/player2/standing.png");
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

/*
 * 1p控制方法 ← →左右行走
 * 1 2分别为出拳和出腿
*/
void Player2P::keyBoardListener()
{
  if(m_collidedState != ISATTACKED)    //只有不是被攻击(处于硬直状态键盘的操作才是有效的）
    {
        if(m_state == PUNCH || m_state == KICK)
            return;
        if(GetAsyncKeyState(VK_LEFT))
        {
            m_state = RUN;
            m_direction = LEFT;
        }
        else if(GetAsyncKeyState(VK_RIGHT))
        {
            m_state = RUN;
            m_direction = RIGHT;
        }
        else
            m_state = STAND;
        // 出拳和出腿控制
        if(GetAsyncKeyState(VK_NUMPAD1))
        {
            m_state = PUNCH;
        }
        if(GetAsyncKeyState(VK_NUMPAD2))
        {
            m_state = KICK;
        }
    }
  else
      return;
}
