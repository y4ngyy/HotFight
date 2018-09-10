#include "startwindow.h"
#include "ui_startwindow.h"
#include <QPalette>
#include <QCloseEvent>

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    // 设置固定大小
    setFixedSize(QSize(600,500));
    ui->setupUi(this);
    setWindowTitle("开始游戏");
    // 设置窗口背景图
    setAutoFillBackground(true);
    QPalette back = this->palette();
    setStyleSheet("background-repeat:no-repeat;");
    back.setBrush(QPalette::Window, QBrush(
                      QPixmap(":/images/startui_background.gif").scaled(
                          this->size(),
                          Qt::IgnoreAspectRatio,
                          Qt::SmoothTransformation)));
    setPalette(back);
<<<<<<< HEAD
    setWindowIcon(QIcon(":/images/icon.png"));
=======
//初始化打开窗口的类型
    m_windowType=NOWINDOW;

>>>>>>> origin/增加了对话框的功能
    // 初始化指针
    m_localGame = nullptr;
    m_netConnectDialog = nullptr;
    connect(m_localGame,&LocalGameWindow::returnToStartWindowSignal,this,&StartWindow::closeLocalGame);
}

StartWindow::~StartWindow()
{
    delete ui;
//    if(m_localGame != nullptr)
//        delete m_localGame;
//    if(m_netConnectDialog != nullptr)
//        delete m_netConnectDialog;
}

void StartWindow::setWindowType(WINDOWTYPE type)
{
    m_windowType=type;
}

StartWindow::WINDOWTYPE StartWindow::getWindowType()const
{
    return m_windowType;
}

void StartWindow::on_btnLocalGame_clicked()
{
    if(m_localGame!=NULL)
    {
        delete m_localGame;
        m_localGame=NULL;
    }
    // 打开单机游戏画面,如果没有窗口被打开的话
    if(m_localGame==NULL)
    {
        m_localGame = new LocalGameWindow();
        m_windowType=LOCAL;
        m_localGame->show();
        connect(m_localGame,&LocalGameWindow::returnToStartWindowSignal,this,&StartWindow::closeLocalGame);
    }

}

void StartWindow::on_btnNetGame_clicked()
{
   if(m_netConnectDialog!=NULL)
   {
       delete m_netConnectDialog;
       m_netConnectDialog=NULL;
   }
   if(m_netConnectDialog==NULL)
   {
       m_netConnectDialog= new NetConnectDialog;
       m_windowType=NET;
       m_netConnectDialog->show();

   }
}

void StartWindow::on_btnHelp_clicked()
{
    m_helpWindow = new Help();
    m_helpWindow->show();
}
void StartWindow::closeLocalGame()
{
    m_localGame->close();
    if(m_localGame!=NULL)
    {

        delete m_localGame;
        m_localGame=NULL;

    }
}
