#include "localgamewindow.h"
#include "startwindow.h"
#include "netconnectdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 开始界面
    StartWindow s;
    s.show();
    NetConnectDialog n;
    n.show();
    return a.exec();
}
