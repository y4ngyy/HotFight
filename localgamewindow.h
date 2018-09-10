#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "playeritem.h"
#include "player1p.h"
#include "player2p.h"
#include"localgamescene.h"
#include <QGraphicsView>
#include <QWidget>
#include<QEvent>
#include<QKeyEvent>
#include <QCloseEvent>


class LocalGameWindow : public QGraphicsView
{
    Q_OBJECT

public:
    LocalGameWindow(QWidget *parent = nullptr);
    ~LocalGameWindow();
protected:
private:

    LocalGameScene *m_localgamescene;   //测试需要
};

#endif // MAINWINDOW_H
