#ifndef NETGAMEWINDOW_H
#define NETGAMEWINDOW_H

#include "netgamescene.h"
#include <QGraphicsView>

class NetGameWindow : public QGraphicsView
{
    Q_OBJECT
public:
    NetGameWindow(QWidget *parent = nullptr);


private:
    NetGameScene m_netGameScene;

};

#endif // NETGAMEWINDOW_H
