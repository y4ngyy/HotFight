#include "netgamescene.h"
#include "net.h"
#include <QtDebug>
#include <QJsonDocument>
#include <healthybar.h>

NetGameScene::NetGameScene(QString ip, int port)
{
    //设置初始的ip 和 端口
    setObjectIp(ip);
    setObjectPort(port);
    m_netType = C1;
//    isSceneUdpConnected=false;
    m_udpSocket = new QUdpSocket(this);
    m_udpSocket->bind(static_cast<quint16>(m_objectPort));
    timerId = startTimer(100);
    connect(m_udpSocket,&QUdpSocket::readyRead,this,&NetGameScene::onReceiveUdp);
    // 设置Scene大小
    setSceneRect(0,0,600,442);
    // 初始化人物位置
    m_item1.setPositonInfo(200, 300);
    m_item2.setPositonInfo(500, 300);
    //设置血条精力条的位置
    healthBar_1.setType(P1);
    healthBar_2.setType(P2);
    healthBar_1.setPos(0,0);
    healthBar_2.setPos(600-healthBar_2.getMaxWdith(),0);
    energyBar_1.setType(P1);
    energyBar_2.setType(P2);
    energyBar_1.setPos(0,healthBar_1.getHeight());
    energyBar_2.setPos(600-energyBar_2.getMaxWdith(),healthBar_1.getHeight());
    //增加血条精力条
    addItem(&healthBar_1);
    addItem(&healthBar_2);
    addItem(&energyBar_1);
    addItem(&energyBar_2);
    addItem(&m_item1);
    addItem(&m_item2);
    addItem(&m_explodingitem);
    m_explodingitem.setVisible(false);
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
        Rule::recoverEnergy(m_item1);
        Rule::recoverEnergy(m_item2);
        Rule::recoverTenacity(m_item1);
        Rule::recoverTenacity(m_item2);
        qDebug()<<"1:"<<m_item1.getBlood()<<"||"<<m_item1.getEnergy()<<"||"<<m_item1.getTenacity();
        qDebug()<<"2:"<<m_item2.getBlood()<<"||"<<m_item2.getEnergy()<<"||"<<m_item2.getTenacity();
        isCollided(m_item1,m_item2);   //1P 和2P的 碰撞检测，必须放在攻击检测的前面，否则ISATTACKED会被替换成 ISCOLLIDEDLEFT，以后可以考虑整合成一个大函数
        //人物的攻击判定  测试
        m_item1.JudgeingAttack();
        if(m_item1.getAttackedFlag())
        {
            if(isAttacked(m_item1,m_item2))
            {
               if(m_item2.getCollidedState()==PlayerItem::ISCOLLIDEDLEFT)
               {
                   m_explodingitem.setX(m_item2.x());
                   m_explodingitem.setY(m_item2.y()-m_item2.getHeight()*4/5);
                   //把爆炸物状态视为可见
                   m_explodingitem.updatePos();
                   m_explodingitem.isItemVisable=true;
                   qDebug()<<m_explodingitem.getX()<<m_explodingitem.getY()<<m_explodingitem.scenePos();
               }
               else if(m_item2.getCollidedState()==PlayerItem::ISCOLLIDEDRIGHT)
               {
                   m_explodingitem.setX(m_item2.x()+m_item2.getWidth());
                   m_explodingitem.setY(m_item2.y()-m_item2.getHeight()*4/5);
                   //把爆炸物状态视为可见
                   m_explodingitem.updatePos();
                   m_explodingitem.isItemVisable=true;
                   qDebug()<<m_explodingitem.getX()<<m_explodingitem.getY()<<m_explodingitem.scenePos();
               }
            }
        }
        m_item2.JudgeingAttack();
        if(m_item2.getAttackedFlag())
        {
            if(isAttacked(m_item2,m_item1))
            {
               if(m_item1.getCollidedState()==PlayerItem::ISCOLLIDEDLEFT)
               {
                    m_explodingitem.setX(m_item1.x()+m_item1.getWidth()*2/5);
                    m_explodingitem.setY(m_item1.y()-m_item1.getHeight()*4/5);
                    //把爆炸物状态视为可见
                    m_explodingitem.updatePos();
                    m_explodingitem.isItemVisable=true;
                    qDebug()<<m_explodingitem.getX()<<m_explodingitem.getY()<<m_explodingitem.scenePos();
               }
               else if(m_item1.getCollidedState()==PlayerItem::ISCOLLIDEDRIGHT)
               {
                   m_explodingitem.setX(m_item1.x()+m_item1.getWidth()*3/5);
                   m_explodingitem.setY(m_item1.y()-m_item1.getHeight()*4/5);
                   //把爆炸物状态视为可见
                   m_explodingitem.updatePos();
                   m_explodingitem.isItemVisable=true;
                   qDebug()<<m_explodingitem.getX()<<m_explodingitem.getY()<<m_explodingitem.scenePos();

               }
            }
        }
        //刷新爆炸物
        if(m_explodingitem.isItemVisable)
        {

            m_explodingitem.setVisible(true);
        }
        else
        {

             m_explodingitem.setVisible(false);
        }


        //刷新血条和精力条
        healthBar_1.setBlood(m_item1.getBlood());
        healthBar_2.setBlood(m_item2.getBlood());
        energyBar_1.setEnergy(m_item1.getEnergy());
        energyBar_2.setEnergy(m_item2.getEnergy());

        // 游戏线程 刷新视图和人物跑动 碰撞 跳跃
        m_item1.jump();
        m_item2.jump();
        m_item1.run();
        m_item2.run();
        m_item1.attackingMove();
        m_item2.attackingMove();
        // 传输数据
        if(m_netType == C1)
            Net::sendJsInfo(m_udpSocket, m_item1);
        else
            Net::sendJsInfo(m_udpSocket, m_item2);
        // 碰撞
        m_item1.updatePos();
        m_item2.updatePos();

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
    if(m_netType == C1)
        Net::setNetWorkInfo(doc.object(), m_item2);
    else
        Net::setNetWorkInfo(doc.object(), m_item1);
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

// 事件分发
bool NetGameScene::event(QEvent *event)
{
    switch(event->type())
    {
        case QEvent::KeyPress:
            if(m_netType == C1)
                sendEvent(&m_item1, event);
            else
                sendEvent(&m_item2, event);
            return true;
        case QEvent::KeyRelease:
            if(m_netType == C1)
                sendEvent(&m_item1, event);
            else
                sendEvent(&m_item2, event);
            return true;
        default:
            return GameScene::event(event);
    }
}

