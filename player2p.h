#ifndef PLAYERITEM2_H
#define PLAYERITEM2_H
#include<playeritem.h>

class Player2P:public PlayerItem    //继承基类
{
public:
   Player2P();
protected:
    void keyPressEvent(QKeyEvent *);     //重载基类的键盘函数
    void keyReleaseEvent(QKeyEvent *);

    virtual void loadResource();  //重载基类的资源加载函数
};

#endif // PLAYERITEM2_H
