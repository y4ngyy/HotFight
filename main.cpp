#include "localgamewindow.h"
#include "startwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 开始界面
    StartWindow s;
    s.show();
    return a.exec();
}
