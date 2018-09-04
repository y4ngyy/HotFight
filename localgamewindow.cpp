#include "localgamewindow.h"
#include <QPixmap>

LocalGameWindow::LocalGameWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    setFixedSize(600,442);
    setScene(&m_localgamescene);
    setStyleSheet("background:url(:/images/background/background_1.png);"
                  "border: 0px;"
                  "padding: 0px;");
}

LocalGameWindow::~LocalGameWindow()
{

}
