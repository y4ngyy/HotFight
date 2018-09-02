#include "localgamewindow.h"
#include <QPixmap>

LocalGameWindow::LocalGameWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    //初始化QGraphicsView对象

    // 初始化QGraphicsScene对象
    //    m_scene = new QGraphicsScene(this);
    //    m_scene->addItem(&item);
    //    m_scene->addItem(&item2);

    setScene(&m_gamescene);
}

LocalGameWindow::~LocalGameWindow()
{

}
