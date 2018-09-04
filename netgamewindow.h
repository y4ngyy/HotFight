#ifndef NETGAMEWINDOW_H
#define NETGAMEWINDOW_H

#include "netgamescene.h"
#include <QGraphicsView>
#include<QCloseEvent>

class NetGameWindow : public QGraphicsView
{
    Q_OBJECT
public:
    NetGameWindow(QWidget *parent = nullptr);
protected:
    void closeEvent(QCloseEvent *);

private:
    NetGameScene m_netGameScene;

};

#endif // NETGAMEWINDOW_H
