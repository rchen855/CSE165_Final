#include "Headers/Enemy.h"
#include "Headers/Player.h"
#include "Headers/Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game* game;

Enemy::Enemy() {
    health = 1;
    speed = 5;
    int random_number = rand() % 700;
    setPos(random_number,0);

    // creates the Enemy
    setPixmap(QPixmap(":/images/external/enemy.png"));

    // connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

int Enemy::getHealth() {
    return health;
}

void Enemy::decreaseHealth() {
    health--;
}

void Enemy::setHealth(int h) {
    health = h;
}

void Enemy::move() {
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
