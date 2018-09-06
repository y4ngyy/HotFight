#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsObject>

class Bar: public QGraphicsObject
{
public:
    Bar();
    void setBlood(double);

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
