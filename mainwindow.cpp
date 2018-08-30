#include "mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    //初始化QGraphicsView对象

    // 初始化QGraphicsScene对象
    m_scene = new QGraphicsScene(this);
    m_scene->addItem(&item);
    item.setFocus();
    setScene(m_scene);
}

MainWindow::~MainWindow()
{

}
