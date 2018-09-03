#include "netgamescene.h"

NetGameScene::NetGameScene()
{
    m_udpSocket = new QUdpSocket(this);
    m_udpSocket->bind(6666);
    m_netType = CLIENT;
    m_netItem1 = new NetPlayerItem(NetPlayerItem::C1);
    m_netItem2 = new NetPlayerItem(NetPlayerItem::C2);

    timerId = startTimer(100);

    //槽函数连接
    connect(m_udpSocket,&QUdpSocket::readyRead,this,&NetGameScene::onReceiveUdp);
}

NetGameScene::~NetGameScene()
{
   if(m_netItem1!=NULL)
   {
       delete  m_netItem1;
       m_netItem1=NULL;
   }
   if(m_netItem2!=NULL)
   {
       delete  m_netItem1;
       m_netItem2=NULL;
   }
}

void NetGameScene::timerEvent(QTimerEvent *event)
{    if(event->timerId() == timerId)
    {
        isCollided(*m_netItem1,*m_netItem2);   //1P 和2P的 碰撞检测，必须放在攻击检测的前面，否则ISATTACKED会被替换成 ISCOLLIDEDLEFT，以后可以考虑整合成一个大函数
        //人物的攻击判定  测试
        if(isAttacked(*m_netItem1,*m_netItem2))
            qDebug()<<"item2被攻击了！"<<m_netItem2->getState()<<endl;
        if(isAttacked(*m_netItem2, *m_netItem1))
             qDebug()<<"item1被攻击了！"<<m_netItem1->getState()<<endl;

        // 游戏线程 刷新视图和人物跑动 碰撞
        m_netItem1->run();
        m_netItem2->run();

        // 根据netType来设置控制的是item1还是itme2
        if(m_netType == SERVER)
        {
            m_netItem1->keyBoardListener();
            m_netItem2->NetKeyBoardListener();
            m_udpSocket->writeDatagram(m_netItem1->getKey().toUtf8().data(),
                                       QHostAddress("127.0.0.1"),6666);
        }
        else
        {
            m_netItem1->NetKeyBoardListener();
            m_netItem2->keyBoardListener();
            m_udpSocket->writeDatagram(m_netItem2->getKey().toUtf8().data(),
                                       QHostAddress("127.0.0.1"),6666);
        }
        m_netItem1->updatePos();
        m_netItem2->updatePos();
    }
}

//
void NetGameScene::setNetType( NETTYPE t_netType)
{
    m_netType=t_netType;
}
NetGameScene::NETTYPE  NetGameScene::getNetType(void)const
{
    return m_netType;
}

//接受键盘输入的槽函数
void NetGameScene::onReceiveUdp()
{
    qint64 size=m_udpSocket->pendingDatagramSize();
    QByteArray array;
    array.resize(size);
    m_udpSocket->readDatagram(array.data(),size);
    if(m_netType==SERVER)
    {
        m_netItem2->setKey(array.data());
    }
    else
    {
        m_netItem1->setKey(array.data());
    }
}
