#ifndef PLAYERITEM_H
#define PLAYERITEM_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QList>
#include <QKeyEvent>
#include <QWidget>
#include <QObject>
#include <QGraphicsObject>
#include <QTimerEvent>

enum STATE{JUMP, PUNCH, KICK, RUN, STAND};
enum DIRECTION{LEFT, RIGHT};

/*
 *  角色基类
 *  1P 2P需重载键盘操作事件
 *  子类需重载加载资源函数
*/
class PlayerItem : public QGraphicsObject
{
public:
    PlayerItem();
    ~PlayerItem();

    // 功能函数
    // 调试：需在scene中调用
    void run();

    // GameScene中调用设置人物位置
    void setPositonInfo(qreal, qreal);

    // 刷新设置人物位置
    void updatePos();

    //所有的get和set函数
    void setState(STATE);
    STATE getState()const;
    void setDirection(DIRECTION);
    DIRECTION getDirection()const;
    void setX(qreal);
    qreal getX()const;
    void setY(qreal);
    qreal getY()const;
    void setHeight(int);
    int getHeight()const;
    void setWidth(int);
    int getWidth()const;
    void setSpeed(int);
    int getSpeed()const;
    void setBlood(int);
    int  getBlood()const;

protected:

    //人物状态变量 子类重载暂时需直接修改 变为保护型
    STATE m_state;
    DIRECTION m_direction;

    // 加载图片资源
    // 子类需直接加载资源 将私有变成保护型
    QPixmap p_standing;
    QList<QPixmap> p_running;
    QList<QPixmap> p_punch;

    //设置item碰撞边缘
    QRectF boundingRect()const;

    // 子类需继承的初始化函数，初始化坐标变量 资源加载 基础属性等
    virtual void init() = 0;

    // 尝试键盘无冲操作 子类重载 并在timeEvent中执行
    virtual void keyBoardListener() = 0;

private:
    // 绘制函数
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

    // 在Scene坐标下的 x,y(item坐标系下的原点)
    qreal m_x;
    qreal m_y;

    // 图片资源的宽高
    int m_height;
    int m_width;
    void setPixmapInfo();

    //动画控制变量
    int runIndex;
    int punchIndex;

    // 人物属性
    int m_speed; //奔跑速度
    int m_blood; //生命值
};

#endif // PLAYERITEM_H
