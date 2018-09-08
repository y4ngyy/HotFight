#include "netgamescene.h"
#include <QtDebug>
#include <QJsonDocument>

NetGameScene::NetGameScene(QString ip, int port)
{
    //设置初始的ip 和 端口
    setObjectIp(ip);
    setObjectPort(port);
    m_netType = CLIENT;
//    isSceneUdpConnected=false;
    m_udpSocket = new QUdpSocket(this);
    m_udpSocket->bind(m_objectPort);
    timerId = startTimer(100);

//    //槽函数连接
//    connect(m_udpSocket,&QUdpSocket::connected,[=]()
//    {
//        qDebug()<<"连接成功！";
//        isSceneUdpConnected=true;
//    });
    connect(m_udpSocket,&QUdpSocket::readyRead,this,&NetGameScene::onReceiveUdp);

}

NetGameScene::~NetGameScene()
{
   if(m_udpSocket!=NULL)
   {
       m_udpSocket->disconnectFromHost();
       delete m_udpSocket;
       m_udpSocket=NULL;
   }
}

void NetGameScene::timerEvent(QTimerEvent *event)
{    if(event->timerId() == timerId)
    {
        // 增加游戏线程
    }
}

//set和get函数
void NetGameScene::setNetType( NETTYPE t_netType)
{
    m_netType=t_netType;
}
NetGameScene::NETTYPE  NetGameScene::getNetType(void)const
{
    return m_netType;
}

void NetGameScene::setObjectIp(const QString ip)
{
    m_objectIp=ip;
}

QString NetGameScene::getObjectIp(void)const
{
    return m_objectIp;
}
void NetGameScene::setObjectPort(const int port)
{
    m_objectPort=port;
}

int NetGameScene::getObjectPort(void)const
{
    return m_objectPort;
}

//接受键盘输入的槽函数
void NetGameScene::onReceiveUdp()
{
    qint64 size=m_udpSocket->pendingDatagramSize();
    QByteArray array;
    array.resize(size);
    qDebug() <<"收到消息";
    m_udpSocket->readDatagram(array.data(),size);
    qDebug() <<array.data();
    QJsonDocument doc = QJsonDocument::fromJson(array);
}
//关闭套接字的函数
void NetGameScene::closeUdpSocket()
{
    killTimer(timerId);
    if(m_udpSocket!=NULL)
    {
            m_udpSocket->abort();
    }
}

