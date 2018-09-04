#include "netgamewindow.h"

NetGameWindow::NetGameWindow(QString ip, int port,QWidget *parent)
                             : QGraphicsView(parent),m_netGameScene(ip,port)
{
    setScene(&m_netGameScene);

//    //下面这部分呢代码有点小问题
//    //连接对象的信息
//    QString objectPlayerInfo;
//    objectPlayerInfo="Ip:"+m_netGameScene.getObjectIp()
//                +QString(" 端口号：[%1]").arg(m_netGameScene.getObjectPort());
//    if(m_netGameScene.isSceneUdpConnected)
//    {
//        QMessageBox::information(this,"信息","与"+objectPlayerInfo+"连接成功，尽情玩耍把！");
//    }
//    else
//    {
//         QMessageBox::information(this,"错误","连接失败");
//    }
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
