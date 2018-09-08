#include "netgamewindow.h"

NetGameWindow::NetGameWindow(QString ip, int port,QWidget *parent)
                             : QGraphicsView(parent),m_netGameScene(ip,port)
{

    setFixedSize(600,442);
    setScene(&m_netGameScene);
    setStyleSheet("background:url(:/images/background/background_1.png);"
                  "border: 0px;"
                  "padding: 0px;");
}

void NetGameWindow::closeEvent(QCloseEvent *e)
{
    m_netGameScene.closeUdpSocket();
}

//用来调用子类的set函数
void NetGameWindow::setSceneNetType(NetGameScene::NETTYPE Type)
{
    m_netGameScene.setNetType(Type);
}

 NetGameScene::NETTYPE NetGameWindow::getSceneNetType()const
 {
     return m_netGameScene.getNetType();
 }

 void NetGameWindow::setSceneIp(QString ip)
 {
    m_netGameScene.setObjectIp(ip);
 }

 QString NetGameWindow::getSceneIp()const
 {
     return m_netGameScene.getObjectIp();
 }
 void NetGameWindow::setScenePort(int port)
 {
     m_netGameScene.setObjectPort(port);
 }

 int NetGameWindow::getScenePort()const
 {
     return m_netGameScene.getObjectPort();
 }
