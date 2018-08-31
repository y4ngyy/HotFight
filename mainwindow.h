#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "playeritem.h"
#include "player1p.h"
#include "player2p.h"
#include <QGraphicsView>
#include <QWidget>
#include<QEvent>
#include<QKeyEvent>
#include"gamescene.h"

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
private:

    GameScene m_gamescene;   //测试需要
};

#endif // MAINWINDOW_H
