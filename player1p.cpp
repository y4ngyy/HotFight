#include "player1p.h"
#include <QPixmap>
#include <QKeyEvent>
#include <windows.h>

Player1P::Player1P()
{
    init_3();
}

/*
 * 1p控制方法 W D左右行走
 * J K分别为出拳和出腿
*/
void Player1P::keyBoardListener()
{
    if(m_collidedState != ISATTACKED)    //只有不是被攻击(处于硬直状态键盘的操作才是有效的）
      {
        if(m_state == PUNCH || m_state == KICK)
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
        // 出拳出腿判定 两者不能状态重叠 出腿优先
        if(GetAsyncKeyState(74))
        {
            m_state = PUNCH;
        }
        if(GetAsyncKeyState(75))
        {
            m_state = KICK;
        }
    }
    else
      return;
}

