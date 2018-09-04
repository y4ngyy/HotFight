#ifndef NETCONNECTDIALOG_H
#define NETCONNECTDIALOG_H

#include <QDialog>
#include"netgamescene.h"
#include"netgamewindow.h"
#include<QMessageBox>

namespace Ui {
class NetConnectDialog;
}

class NetConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetConnectDialog(QWidget *parent = nullptr);
    ~NetConnectDialog();

private slots:
    void on_clientConnect_clicked();

    void on_clientCancel_clicked();

private:
    Ui::NetConnectDialog *ui;
    NetGameWindow *m_netGameWindow;
};

#endif // NETCONNECTDIALOG_H
