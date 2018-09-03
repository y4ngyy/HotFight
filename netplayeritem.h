#ifndef NETPLAYERITEM_H
#define NETPLAYERITEM_H

#include "playeritem.h"
#include <QJsonObject>

class NetPlayerItem : public PlayerItem
{
public:
    enum ITEMTYPE{PLAYER, NETPLAYER};
    enum CHARACTOR{C1, C2};
    NetPlayerItem(CHARACTOR = C1);


    void keyBoardListener();

    // 数据传输与解析
    QByteArray sendJSInfo();
    void setNetWorkInfo(QJsonObject);
private:
    ITEMTYPE type;

};

#endif // NETPLAYERITEM_H
