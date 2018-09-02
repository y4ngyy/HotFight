#ifndef NETCONNECTDIALOG_H
#define NETCONNECTDIALOG_H

#include <QDialog>

namespace Ui {
class NetConnectDialog;
}

class NetConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetConnectDialog(QWidget *parent = nullptr);
    ~NetConnectDialog();

private:
    Ui::NetConnectDialog *ui;
};

#endif // NETCONNECTDIALOG_H
