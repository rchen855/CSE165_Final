#include "Headers/FasterEnemy.h"
#include <QTimer>
#include "Headers/Enemy.h"
#include "Headers/Player.h"
#include "Headers/Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game* game;
FasterEnemy::FasterEnemy(): Enemy() {
    speed = 7; // Adjust speed for FasterEnemy
    setPixmap(QPixmap(":/images/external/fasterenemy.png"));
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void FasterEnemy::move() {
    // move enemy down
    setPos(x(),y()+speed);
    if (pos().y() > 800) {
        scene()->removeItem(this);
        delete this;
        game->health->decrease();
        return;
    }
    QList<QGraphicsItem*> collisions = collidingItems();
    for (int i = 0; i < collisions.size(); i++) {
        if (typeid(*(collisions[i])) == typeid(Player)) {
            // increate the score
            game->health->decrease();
            // remove from scene
            scene()->removeItem(this);
            // delete both items
            delete this;
            return;
        }
    }
}
