#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>

class Game: public QGraphicsView {
public:
    Game(QWidget* parent=0);
    QGraphicsScene* scene;
    Player* player;
};

#endif // GAME_H
