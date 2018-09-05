#ifndef PLAYER1P_H
#define PLAYER1P_H

#include "playeritem.h"
#include <QKeyEvent>

class Player1P : public PlayerItem
{
public:
    Player1P();
protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

};

#endif // PLAYER1P_H
