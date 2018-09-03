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



/*
 *  角色基类
 *  1P 2P需重载键盘操作事件
 *  子类需重载加载资源函数
*/
class PlayerItem : public QGraphicsObject
{
public:
    enum STATE{JUMP, PUNCH, KICK, RUN, STAND,ISHITTING};      //与运动(角色动画）有关的状态
    enum DIRECTION{LEFT, RIGHT};                                   // ISHITTING 和ISATTACKED所表示的意义相同，但是用在不同的函数上
    enum COLLIDEDSTATE{NORMAL,ISCOLLIDEDLEFT,ISCOLLIDEDRIGHT,ISATTACKED};  //与战斗时碰撞有关的状态 目前ISATTACKED表示格斗游戏中的硬直状态
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
    void setCollidedState(COLLIDEDSTATE);
    COLLIDEDSTATE getCollidedState()const;

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

    //人物状态变量 子类重载暂时需直接修改 变为保护型 在该类的构造函数中初始化
    STATE m_state;
    DIRECTION m_direction;
    COLLIDEDSTATE m_collidedState;

    // 加载图片资源
    // 子类需直接加载资源 将私有变成保护型  在子类的资源加载函数中进行初始化
    QPixmap p_standing;
    QList<QPixmap> p_running;
    QList<QPixmap> p_punch;
    QList<QPixmap> p_ishitting;
    QList<QPixmap> p_kicking;

    //设置item碰撞边缘
    QRectF boundingRect()const;

    // 资源加载函数，子类选择
    void init_1();
    void init_2();

    // 尝试键盘无冲操作 子类重载 并在timeEvent中执行
    virtual void keyBoardListener() = 0;

private:
    // 绘制函数
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

    // 在Scene坐标下的 x,y(item坐标系下的原点)  该属性在scene中调用setPosiition函数进行赋值
    qreal m_x;
    qreal m_y;

    // 图片资源的宽高  加载资源的时候自动初始化
    int m_height;
    int m_width;
    void setPixmapInfo();

    //动画控制变量 如果要添加新变量到该类的构造函数去初始化
    int runIndex;
    int punchIndex;
    int ishittingIndex;
    int kickIndex;

    // 人物属性
    int m_speed; //奔跑速度 在 setinfo中初始化
    int m_blood; //生命值   暂未初始化
};

#endif // PLAYERITEM_H
