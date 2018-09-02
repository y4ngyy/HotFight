#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "playeritem.h"
#include "player1p.h"
#include "player2p.h"
#include"gamescene.h"
#include <QGraphicsView>
#include <QWidget>
#include<QEvent>
#include<QKeyEvent>


class LocalGameWindow : public QGraphicsView
{
    Q_OBJECT

public:
    LocalGameWindow(QWidget *parent = nullptr);
    ~LocalGameWindow();
protected:
private:

    GameScene m_gamescene;   //测试需要
};

#endif // MAINWINDOW_H
