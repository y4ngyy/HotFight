#include "endwindow.h"
#include "ui_endwindow.h"

EndWindow::EndWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndWindow)
{
    setFixedSize(QSize(600,500));
    ui->setupUi(this);
    setWindowTitle("游戏结束");
    setCursor(QCursor(QPixmap(":/images/mouse.png")));
    setAutoFillBackground(true);
    QPalette back = this->palette();
    setStyleSheet("background-repeat:no-repeat;");
    back.setBrush(QPalette::Window, QBrush(
                      QPixmap(":/images/endui_background.gif").scaled(
                          this->size(),
                          Qt::IgnoreAspectRatio,
                          Qt::SmoothTransformation)));
    setPalette(back);
}

EndWindow::~EndWindow()
{
    delete ui;
}

void EndWindow::on_btnRestart_clicked()
{

}

void EndWindow::on_btnReturn_clicked()
{

}


void EndWindow::on_btnQuit_clicked()
{
   this->close();
}
