#include "rule.h"

Rule::Rule()
{

}

void Rule::calculateBlood(PlayerItem &attackItem, PlayerItem &attackedItem)
{
    int t_atk;
    switch (attackItem.m_state)
    {
        case PlayerItem::PUNCH:
            t_atk = attackItem.m_punchATK;
        break;
        case PlayerItem::KICK:
            t_atk = attackItem.m_kickATK;
        break;
        case PlayerItem::SKILL:
            if(attackItem.m_skillType == PlayerItem::NONESKILL)
                return;
            t_atk = attackItem.m_skillATK.at(attackItem.m_skillType);
        break;
        default:
            return;
    }
    double damage=m_damageK1* t_atk * attackItem.m_energy - m_damageK2 * attackedItem.m_energy * attackedItem.m_basicDEF;
    if(damage>=0)
    {
        attackedItem.m_blood -= damage;
    }
    if(attackedItem.m_blood<=0)
        attackedItem.m_blood=0;

}

void Rule::calculateEnergy(PlayerItem &item, int energyReduce)
{
    if(item.m_energy - energyReduce <= 0)
        item.m_energy = 0;
    else
        item.m_energy -= energyReduce;
}

void Rule::calculateTenacity(PlayerItem &attackItem, PlayerItem &attackedItem)
{
    int t_tenaReduce;
    switch (attackItem.m_state)
    {
        case PlayerItem::PUNCH:
            t_tenaReduce = attackItem.m_punchTeReduce;
        break;
        case PlayerItem::KICK:
            t_tenaReduce = attackItem.m_kickTeReduce;
        break;
        case PlayerItem::SKILL:
            if(attackItem.m_skillType == PlayerItem::NONESKILL)
                return;
            t_tenaReduce = attackItem.m_skillTeReduce.at(attackItem.m_skillType);
        default:
            return;
    }
    if(attackedItem.m_tenacity - t_tenaReduce <= 0)
        attackedItem.m_tenacity = 0;
    else
        attackedItem.m_tenacity -= t_tenaReduce;
}

// timerEvent中调用
void Rule::recoverEnergy(PlayerItem &item)
{   
    // 攻击时无法回复精力
    if(item.getState() == PlayerItem::PUNCH || item.getState() == PlayerItem::KICK||item.getState() == PlayerItem::SKILL)
        return;
    if(item.m_energy + 10 >= 100)
        item.m_energy = 100;
    else
        item.m_energy += 10;
}

void Rule::recoverTenacity(PlayerItem &item)
{
    if(item.m_state == PlayerItem::ISHITTING)
    {
        if(item.m_tenacity + 5 >= 100)
            item.m_tenacity = 100;
        else
            item.m_tenacity += 5;
    }
    else
    {
        if(item.m_tenacity + 20 >= 100)
            item.m_tenacity = 100;
        else
            item.m_tenacity += 20;
    }
}
