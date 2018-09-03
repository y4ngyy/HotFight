#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "localgamewindow.h"
#include "netgamewindow.h"
#include <QWidget>

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_btnLocalGame_clicked();

    void on_btnNetGame_clicked();

    void on_btnHelp_clicked();

private:
    Ui::StartWindow *ui;

    // 单机游戏界面
    LocalGameWindow *m_localGame;
    NetGameWindow *m_netGame;

};

#endif // STARTWINDOW_H
