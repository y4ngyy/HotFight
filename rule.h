#ifndef RULE_H
#define RULE_H

#include "playeritem.h"

/*
 * 规则类
 * 用于计算血量，精力，硬直条
 */
class Rule
{
public:
    Rule();
    // 计算血量 精力 韧性（硬直）
    static void calculateBlood(PlayerItem &, PlayerItem &);
    static void calculateEnergy(PlayerItem &, int);
    static void calculateTenacity(PlayerItem &, PlayerItem &);
    // 精力恢复 硬直条恢复
    static void recoverEnergy(PlayerItem &);
    static void recoverTenacity(PlayerItem &);
protected:

private:
    // 伤害系数
    constexpr static double m_damageK1 = 1.0;
    constexpr static double m_damageK2 = 2.0;

    static int s_energyTimerCount;
    static int s_tenacityTimerCount;
};

#endif // RULE_H
