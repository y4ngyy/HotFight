#include "netconnectdialog.h"
#include "ui_netconnectdialog.h"

NetConnectDialog::NetConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetConnectDialog)
{
    ui->setupUi(this);
    setWindowTitle("局域网连接");
    ui->clientIP->setText("127.0.0.1");   //设置默认ip
    ui->clientPort->setText("8888");      //设置默认窗口
    ui->radioButton1P->setChecked(true);   //默认选择1P
    m_netGameWindow=NULL;
}

NetConnectDialog::~NetConnectDialog()
{
    if(m_netGameWindow!=NULL)
    {
        delete m_netGameWindow;
        m_netGameWindow=NULL;
    }
    delete ui;
}

void NetConnectDialog::on_clientConnect_clicked()
{
    if(ui->clientIP->text().isEmpty())
    {
        QMessageBox::information(this,"错误!","请输入连接对象的ip地址");
    }
    else if(ui->clientPort->text().isEmpty())
    {
        QMessageBox::information(this,"错误!","请输入连接对象的端口号");
    }
    else if(!(ui->radioButton1P->isChecked()|| ui->radioButton2P->isChecked())) //如果1P和2P都没选的话
    {
        QMessageBox::information(this,"错误!","请选择是1P还是2P");
    }
    else
    {
        //获取ip 和 端口号
        QString ip=ui->clientIP->text();
        int port=ui->clientPort->text().toInt();

        //初始化一个netGameWindow;
        m_netGameWindow = new NetGameWindow(ip,port);

        //设置1p还是2p
        if(ui->radioButton1P->isChecked())
        {
            m_netGameWindow->setSceneNetType(NetGameScene::SERVER);
        }
        else
        {
            m_netGameWindow->setSceneNetType(NetGameScene::CLIENT);
        }

        m_netGameWindow->show();
        this->close();
    }
}

void NetConnectDialog::on_clientCancel_clicked()
{
    this->close();
}
