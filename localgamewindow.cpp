#include "localgamewindow.h"
#include <QPixmap>

LocalGameWindow::LocalGameWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    setScene(&m_localgamescene);
}

LocalGameWindow::~LocalGameWindow()
{

}
