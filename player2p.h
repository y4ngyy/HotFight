#ifndef PLAYERITEM2_H
#define PLAYERITEM2_H
#include<playeritem.h>

class Player2P:public PlayerItem    //继承基类
{
public:
   Player2P();
protected:
   // 放弃使用键盘事件 使用键盘无冲方案
//    void keyPressEvent(QKeyEvent *);     //重载基类的键盘函数
//    void keyReleaseEvent(QKeyEvent *);

   // 无冲型键盘监听方案
    void keyBoardListener();

    //重载基类的资源加载函数
    void loadResource();
};

#endif // PLAYERITEM2_H
