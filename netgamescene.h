#ifndef NETGAMESCENE_H
#define NETGAMESCENE_H

#include "gamescene.h"
#include "netplayeritem.h"
#include <QUdpSocket>

class NetGameScene : public GameScene
{

public:
//    bool isSceneUdpConnected;
    //构造函数需要ip 和 port作为参数， 并且默认的Ip是127.0.0.1 默认端口是8888
    NetGameScene(QString ip="127.0.0.1", int port=8888);
    ~NetGameScene();
    enum NETTYPE{SERVER,CLIENT};
    //关闭套接字的函数
    void closeUdpSocket();

    //set 和 get的函数

    void setNetType( NETTYPE);
    NETTYPE getNetType(void)const;
    void setObjectIp(const QString);
    QString getObjectIp(void)const;
    void setObjectPort(const int);
    int getObjectPort(void)const;



protected:
    //游戏线程
    void timerEvent(QTimerEvent *);
private slots:
    void onReceiveUdp();
private:
    QString m_objectIp;
    int m_objectPort;
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
