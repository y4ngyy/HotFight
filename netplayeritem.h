#ifndef NETPLAYERITEM_H
#define NETPLAYERITEM_H

#include "playeritem.h"

class NetPlayerItem : public PlayerItem
{
public:
    enum ITEMTYPE{PLAYER, NETPLAYER};
    enum CHARACTOR{C1, C2};
    NetPlayerItem(CHARACTOR = C1);

    void NetKeyBoardListener();
    void keyBoardListener();

    // Scene中调用获取键盘参数
    QString getKey()const;
    void setKey(const QString);
private:
    ITEMTYPE type;

    //客户端和服务器的key的用途不同
    QString key;
};

#endif // NETPLAYERITEM_H
