#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Score.h"
#include "Health.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>

class Game: public QGraphicsView {
public:
    Game(QWidget* parent=0);
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;
};

#endif // GAME_H
