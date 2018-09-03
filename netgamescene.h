#ifndef NETGAMESCENE_H
#define NETGAMESCENE_H

#include "gamescene.h"
#include "netplayeritem.h"
#include <QUdpSocket>

class NetGameScene : public GameScene
{
public:
    NetGameScene();
    ~NetGameScene();
    enum NETTYPE{SERVER,CLIENT};

    //set 和 get的函数

    void setNetType( NETTYPE);
    NETTYPE getNetType(void)const;

protected:
    //游戏线程
    void timerEvent(QTimerEvent *);
private slots:
    void onReceiveUdp();
private:
    // 传输数据套接字
    QUdpSocket *m_udpSocket;
    NetPlayerItem *m_netItem1;
    NetPlayerItem *m_netItem2;

    //游戏线程的id
    int timerId;

    //窗口的类型，是客户端或者是服务器
    // 调试时在构造函数里面设置，实际用对话框设置
    NETTYPE m_netType;


};

#endif // NETGAMESCENE_H
