#ifndef HEALTHBAR_H
#define HEALTHBAR_H


#include<QGraphicsObject>
#include<QPen>
#include<QColor>
#include <QPainter>

class HealthyBar: public QGraphicsObject
{
public:
    HealthyBar();
    void setBlood(double);
    static int getMaxWdith();
    int getHeight()const;
protected:
    QRectF boundingRect() const;
private:
    // 宽度 高度
    static const int MAX_WIDTH = 200; // 生命值为100时
    int m_width;  // 根据blood的数值转换
    int m_height;

    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // HEALTHBAR_H
