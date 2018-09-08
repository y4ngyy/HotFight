#include "player1p.h"
#include <QPixmap>
#include <QKeyEvent>
#include <windows.h>
#include<QDebug>

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
    if(m_state != SKILL &&m_attackedState!=ISATTACKED && m_state != JUMP)
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
            case Qt::Key_W:
                if(getEnergy() < m_jumpEnReduce)
                    return;
                jumpStart();
                m_state = JUMP;
                break;
            case Qt::Key_J:
                if(m_attackClickFlag)
                {
                    m_attackClickFlag = false;
                    // 精力过低时无法出招
                    if(getEnergy() < m_punchEnReduce)
                        return;
                    m_state = PUNCH;
                    // 添加进缓冲区
                    m_buffer.addKey('J');
                }
                break;
            case Qt::Key_K:
                if(m_attackClickFlag)
                {
                    m_attackClickFlag = false;
                    if(getEnergy() < m_kickEnReduce)
                        return;
                    m_state = KICK;
                    // 添加进缓冲区
                    m_buffer.addKey('K');
                }
                break;
            case Qt::Key_I:
                m_state = SKILL;
                judgeSkillType();
                break;
            default:
                break;
        }
    }
}

void Player1P::keyReleaseEvent(QKeyEvent *event)
{
    // 技能释放中或者硬直状态下或者跳跃状态不处理键盘事件
    if(m_state != SKILL &&m_attackedState!=ISATTACKED && m_state != JUMP)
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

//决定攻击判定帧的函数
void Player1P::JudgeingAttack()
{
    switch(m_state)
    {
       case PUNCH:
        // 3到5帧 或者 7到8帧数
            if((punchIndex>=2 && punchIndex<=4)||(punchIndex>=6&&punchIndex<=7))
            {
                m_attackingFlag=true;
                //这段代码是为了在一个区间只计算一次伤害
                //如果伤害还没有被计算
                if(!m_hasDamagedFlag)
                {
                    m_damageFlag=true;
                }
                else
                {
                    //如果已经计算过一次伤害了，那就不能再次造成伤害
                    m_damageFlag=false;
                }
            }
            else
            {
               m_attackingFlag=false;
               //不在判定帧内伤害肯定就还没被计算，至少对于下一批的判定帧来说
               m_hasDamagedFlag=false;
            }
            break;
       case KICK:
        // 7 8 9帧数
            if(kickIndex>=6 && kickIndex<=8)
            {
                m_attackingFlag=true;
                //如果伤害还没有被计算
                if(!m_hasDamagedFlag)
                {
                    m_damageFlag=true;
                }
                else
                {
                    //如果已经计算过一次伤害了，那就不能再次造成伤害
                    m_damageFlag=false;
                }
            }
            else
            {
                 m_attackingFlag=false;
                 m_damageFlag=false;
                 m_hasDamagedFlag=false;
            }
            break;
       case SKILL:
            switch(m_skillType)
            {
                case SKILLONE:
                //技能1 3-5 一段 8-9二段
                    if((skillIndex>=2 && skillIndex<=4) || (skillIndex>=7&&skillIndex<=8))
                    {
                        m_attackingFlag=true;
                        //如果伤害还没有被计算
                        if(!m_hasDamagedFlag)
                        {
                            m_damageFlag=true;
                        }
                        else
                        {
                            //如果已经计算过一次伤害了，那就不能再次造成伤害
                            m_damageFlag=false;
                        }
                    }
                    else
                    {
                        m_damageFlag=false;
                        m_attackingFlag=false;
                        m_hasDamagedFlag=false;
                    }
                    break;

                case SKILLTWO:
                //第3帧
                    if(skillIndex==2)
                    {
                        m_attackingFlag=true;
                        //如果伤害还没有被计算
                        if(!m_hasDamagedFlag)
                        {
                            m_damageFlag=true;
                        }
                        else
                        {
                            //如果已经计算过一次伤害了，那就不能再次造成伤害
                            m_damageFlag=false;
                        }
                    }
                    else
                    {
                        m_damageFlag=false;
                        m_attackingFlag=false;
                        m_hasDamagedFlag=false;
                    }
                    break;

                case SKILLTHREE:
                // 2-4帧
                    if(skillIndex>=1 && skillIndex<=3)
                    {
                        m_attackingFlag=true;
                        //如果伤害还没有被计算
                        if(!m_hasDamagedFlag)
                        {
                            m_damageFlag=true;
                        }
                        else
                        {
                            //如果已经计算过一次伤害了，那就不能再次造成伤害
                            m_damageFlag=false;
                        }
                    }
                    else
                    {
                        m_damageFlag=false;
                        m_attackingFlag=false;
                        m_hasDamagedFlag=false;
                    }
                    break;

                case SKILLFOUR:
                 //3-6帧
                    if(skillIndex>=2 && skillIndex<=5)
                    {
                        m_attackingFlag=true;
                        //如果伤害还没有被计算
                        if(!m_hasDamagedFlag)
                        {
                            m_damageFlag=true;
                        }
                        else
                        {
                            //如果已经计算过一次伤害了，那就不能再次造成伤害
                            m_damageFlag=false;
                        }
                    }
                    else
                    {
                        m_damageFlag=false;
                        m_attackingFlag=false;
                        m_hasDamagedFlag=false;
                    }
                    break;
                case SKILLFIVE:
                 //3-5帧
                    if(skillIndex>=2 && skillIndex<=4)
                    {
                        m_attackingFlag=true;
                        //这段代码是为了在一个区间只计算一次伤害
                        if(!m_hasDamagedFlag)
                        {
                            m_damageFlag=true;
                        }
                        else
                        {
                            //如果已经计算过一次伤害了，那就不能再次造成伤害
                            m_damageFlag=false;
                        }
                    }
                    else
                    {
                        m_damageFlag=false;
                        m_attackingFlag=false;
                        m_hasDamagedFlag=false;
                    }
                    break;
                case SKILLSIX:
                //技能6 5-6 一段 11-13二段
                    if((skillIndex>=4 && skillIndex<=5) || (skillIndex>=10&&skillIndex<=12))
                    {
                        m_attackingFlag=true;
                        //这段代码是为了在一个区间只计算一次伤害
                        if(!m_hasDamagedFlag)
                        {
                            m_damageFlag=true;
                        }
                    }
                    else
                    {
                        m_damageFlag=false;
                        m_attackingFlag=false;
                        m_hasDamagedFlag=false;
                    }
                    break;
                default:
                    {
                        m_attackingFlag=false;
                        m_damageFlag=false;
                        m_hasDamagedFlag=false;
                    }
                    break;
            }
            break;

       default:
            {
                m_attackingFlag=false;
                m_damageFlag=false;
                m_hasDamagedFlag=false;
            }
            break;
    }
}
