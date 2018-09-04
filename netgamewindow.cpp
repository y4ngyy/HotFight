#include "netgamewindow.h"

NetGameWindow::NetGameWindow(QWidget *parent)
                             : QGraphicsView(parent)
{
    setScene(&m_netGameScene);
}

void NetGameWindow::closeEvent(QCloseEvent *e)
{
    m_netGameScene.closeUdpSocket();
}
