#ifndef ENERGYBAR_H
#define ENERGYBAR_H

#include<QGraphicsObject>
#include<QPen>
#include<QColor>
#include <QPainter>

class EnergyBar : public QGraphicsObject
{
public:
    EnergyBar();
    void setEnergy(double);
    static int getMaxWdith();
    int getHeight()const;
protected:
    QRectF boundingRect() const;
private:
    // 宽度 高度
    static const int MAX_WIDTH = 180; // 生命值为100时
    int m_width;  // 根据blood的数值转换
    int m_height;

    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // ENERGYBAR_H
