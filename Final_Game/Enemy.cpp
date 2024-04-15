#include "Enemy.h"
#include "Player.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game* game;

Enemy::Enemy() {
    // set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // creates the bullet
    setRect(0,0,100,100);

    // connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // move enemy down
    int speed = 5;
    setPos(x(),y()+speed);
    if (pos().y() > 800) {
        scene()->removeItem(this);
        delete this;
        game->health->decrease();
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
