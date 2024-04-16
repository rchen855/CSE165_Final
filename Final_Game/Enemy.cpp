#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game* game;

Enemy::Enemy() {
    game->increaseCount();
    qDebug() << "adding enemy " << game->getEnemyCount();
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
        game->decreaseCount();
        qDebug() << "removing enemy " << game->getEnemyCount();
    }
    QList<QGraphicsItem*> collisions = collidingItems();
    for (int i = 0; i < collisions.size(); i++) {
        if (typeid(*(collisions[i])) == typeid(Player)) {
            // increate the score
            game->health->decrease();
            game->decreaseCount();
            qDebug() << "removing enemy " << game->getEnemyCount();
            // remove from scene
            scene()->removeItem(this);
            // delete both items
            delete this;
            return;
        }
    }
}
