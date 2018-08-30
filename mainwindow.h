#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "playeritem.h"
#include "player1p.h"
#include "player2p.h"
#include <QGraphicsView>
#include <QWidget>
#include<QEvent>
#include<QKeyEvent>
#include"FightScene.h"

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
private:
//    QGraphicsScene *m_scene;    //测试注释掉了

//    Player1P item;
//    Player2P item2;

      FightScene m_fightscene;   //测试需要
};

#endif // MAINWINDOW_H
