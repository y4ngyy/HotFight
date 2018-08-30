#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "playeritem.h"
#include "player1p.h"
#include "player2p.h"
#include <QGraphicsView>
#include <QWidget>


class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
private:
    QGraphicsScene *m_scene;
    Player1P item;
    Player2P item2;
};

#endif // MAINWINDOW_H
