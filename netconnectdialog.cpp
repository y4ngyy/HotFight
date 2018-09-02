#include "netconnectdialog.h"
#include "ui_netconnectdialog.h"

NetConnectDialog::NetConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetConnectDialog)
{
    ui->setupUi(this);
    setWindowTitle("局域网连接");
}

NetConnectDialog::~NetConnectDialog()
{
    delete ui;
}
