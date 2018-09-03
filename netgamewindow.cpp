#include "netgamewindow.h"

NetGameWindow::NetGameWindow(QWidget *parent)
                             : QGraphicsView(parent)
{
    setScene(&m_netGameScene);
}
