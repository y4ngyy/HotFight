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
   enum STATE{JUMP, PUNCH, KICK, RUN, STAND,ISATTCAKED};
   enum DIRECTION{LEFT, RIGHT};
    PlayerItem();
    ~PlayerItem();
    //把枚举常量放在类里

    //set 和 get函数
    PlayerItem:: STATE getState();
    void setState(STATE);

    PlayerItem:: DIRECTION getDirection();
    void setDirection(DIRECTION);

    qreal getX()const;
    void setX(qreal);

    qreal getY()const;               //为什么不能加const?
    void setY(qreal);


protected:
    //设置item碰撞边缘
    QRectF boundingRect() const;

    // 键盘事件
    // 用基类调试时可以不用注释掉
//    void keyPressEvent(QKeyEvent *);
//    void keyReleaseEvent(QKeyEvent *);

    // timer事件 用于重绘图
    void timerEvent(QTimerEvent *);

    // 子类需继承的加载资源函数
    // 调试时注释掉
    virtual void loadResource() ;


    // 加载图片资源
    // 子类需直接加载资源 将私有变成保护型
    QPixmap p_standing;
    QList<QPixmap> p_running;
    QList<QPixmap> p_punch;
    QList<QPixmap> p_shitting;


    //人物状态变量 子类重载暂时需直接修改 变为保护型
    STATE m_state;
    DIRECTION m_direction;

    // 尝试键盘无冲操作 子类重载 并在timeEvent中执行
    virtual void keyBoardListener();
private:
    // 绘制函数
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

    // 图像属性变量
    qreal m_x;
    qreal m_y;
    qreal m_height;
    qreal m_width;
    void setInfo();  //根据状态设置属性

    //动画控制变量
    int runIndex;
    int punchIndex;
    int timerId;
    int shittingIndex;

    // 功能函数
    void run();

    // 人物属性
    int m_speed; //奔跑速度
    int m_blood; //生命值
};

#endif // PLAYERITEM_H
