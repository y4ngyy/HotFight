#ifndef NET_H
#define NET_H

#include "playeritem.h"
#include <QUdpSocket>
#include <QJsonObject>

class Net
{
public:
    Net();
    static void setNetWorkInfo(QJsonObject, PlayerItem &);
    static void sendJsInfo(QUdpSocket *, PlayerItem &);
    static void setNetInfo(QString, quint16);
private:
    static QString m_objectIp;
    static quint16 m_objectPort;
};

#endif // NET_H
